/*===========================================================================*\
 *                                                                           *
 *                              OpenFlipper                                  *
 *      Copyright (C) 2001-2011 by Computer Graphics Group, RWTH Aachen      *
 *                           www.openflipper.org                             *
 *                                                                           *
 *---------------------------------------------------------------------------*
 *  This file is part of OpenFlipper.                                        *
 *                                                                           *
 *  OpenFlipper is free software: you can redistribute it and/or modify      *
 *  it under the terms of the GNU Lesser General Public License as           *
 *  published by the Free Software Foundation, either version 3 of           *
 *  the License, or (at your option) any later version with the              *
 *  following exceptions:                                                    *
 *                                                                           *
 *  If other files instantiate templates or use macros                       *
 *  or inline functions from this file, or you compile this file and         *
 *  link it with other files to produce an executable, this file does        *
 *  not by itself cause the resulting executable to be covered by the        *
 *  GNU Lesser General Public License. This exception does not however       *
 *  invalidate any other reasons why the executable file might be            *
 *  covered by the GNU Lesser General Public License.                        *
 *                                                                           *
 *  OpenFlipper is distributed in the hope that it will be useful,           *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
 *  GNU Lesser General Public License for more details.                      *
 *                                                                           *
 *  You should have received a copy of the GNU LesserGeneral Public          *
 *  License along with OpenFlipper. If not,                                  *
 *  see <http://www.gnu.org/licenses/>.                                      *
 *                                                                           *
\*===========================================================================*/

/*===========================================================================*\
 *                                                                           *
 *   $Revision: 16368 $                                                       *
 *   $Author: tenter $                                                      *
 *   $Date: 2013-02-20 22:25:15 +0800 (Wed, 20 Feb 2013) $                   *
 *                                                                           *
\*===========================================================================*/

#include "ShaderGenerator.hh"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QTextStream>
#include <QGLFormat>


namespace ACG
{

#define LIGHTING_CODE_FILE "ShaderGen/SG_LIGHTING.GLSL"



int ShaderProgGenerator::numModifiers_ = 0;
ShaderModifier* ShaderProgGenerator::modifiers_[32] = {0};



ShaderGenerator::ShaderGenerator()
{
  version_ = "#version 150"; 
}

ShaderGenerator::~ShaderGenerator()
{

}


void ShaderGenerator::initVertexShaderIO(const ShaderGenDesc* _desc)
{


  addInput("vec4 inPosition");
  addOutput("vec4 outVertexPosCS");


  if (_desc->shadeMode != SG_SHADE_UNLIT)
    addInput("vec3 inNormal");

  if (_desc->textured)
  {
    addInput("vec2 inTexCoord");
    addOutput("vec2 outVertexTexCoord");
  }
  if (_desc->vertexColors)
    addInput("vec4 inColor");


  if (_desc->shadeMode == SG_SHADE_PHONG)
  {
    addOutput("vec3 outVertexNormal");
    addOutput("vec4 outVertexPosVS");
  }


  std::string strColorOut = "";


  if (_desc->shadeMode == SG_SHADE_FLAT)
    if (_desc->geometryShader)
      strColorOut = "vec4 outVertexColor";
    else {
      // Bypass the output setter, as we have to set that directly with the flat.
      addStringToList("vec4 outVertexColor", &outputs_, "flat out ", ";");
    }
  else {
    if (_desc->shadeMode == SG_SHADE_GOURAUD || _desc->vertexColors)
      strColorOut = "vec4 outVertexColor";
  }

  if (strColorOut.size())
    addOutput(strColorOut.c_str());
}

void ShaderGenerator::initGeometryShaderIO(const ShaderGenDesc* _desc) {

  // Define input of the geometry shader
  switch (_desc->geometryShaderInput) {
    case SG_GEOMETRY_IN_TRIANGLES: // 3 points of the triangle
      addStringToList("layout(triangles)", &inputs_, "", " in;");
      break;
    case SG_GEOMETRY_IN_TRIANGLES_ADJACENCY: // 6 points (defining 3 triangles , one before, current, one after)
      addStringToList("layout(triangles_adjacency)", &inputs_, "", " in;");
      break;
    case SG_GEOMETRY_IN_LINES: // 2 Points describing the line
      addStringToList("layout(lines)", &inputs_, "", " in;");
      break;
    case SG_GEOMETRY_IN_LINES_ADJACENCY: // 4 points ( 1 before, middle two defining line, last one
      addStringToList("layout(lines_adjacency)", &inputs_, "", " in;");
      break;
    case SG_GEOMETRY_IN_POINTS: // Single points
      addStringToList("layout(points)", &inputs_, "", " in;");
      break;
  }

  // Define output of geometry shader
  switch (_desc->geometryShaderOutput) {
    case SG_GEOMETRY_OUT_TRIANGLE_STRIP:
      addStringToList("layout(triangle_strip, max_vertices = "+ QString::number(_desc->geometryShaderMaxOutputPrimitives)+ ")", &outputs_, "", " out;");
      break;
    case SG_GEOMETRY_OUT_LINE_STRIP:
      addStringToList("layout(line_strip, max_vertices = "+ QString::number(_desc->geometryShaderMaxOutputPrimitives)+ ")", &outputs_, "", " out;");
      break;
    case SG_GEOMETRY_OUT_POINTS:
      addStringToList("layout(points, max_vertices = "+ QString::number(_desc->geometryShaderMaxOutputPrimitives)+ ")", &outputs_, "", " out;");
      break;
  }

  addInput("vec4 outVertexPosCS[]");
  addOutput("vec4 outGeometryPosCS");

  if (_desc->textured) {
    addInput("vec2 outVertexTexCoord[]");
    addOutput("vec2 outGeometryTexCoord");
  }


  if (_desc->shadeMode == SG_SHADE_PHONG)
  {
    addInput("vec3 outVertexNormal[]");
    addInput("vec4 outVertexPosVS[]");

    addOutput("vec3 outGeometryNormal");
    addOutput("vec4 outGeometryPosVS");
  }

  QString strColorOut = "";

  if (_desc->shadeMode == SG_SHADE_FLAT || _desc->shadeMode == SG_SHADE_GOURAUD || _desc->vertexColors) {
    addInput("vec4 outVertexColor[]");


    if (_desc->shadeMode == SG_SHADE_FLAT)
      addStringToList("vec4 outGeometryColor", &outputs_, "flat out ", ";");
    else {
      if (_desc->shadeMode == SG_SHADE_GOURAUD || _desc->vertexColors)
        strColorOut = "vec4 outGeometryColor";
    }

    if ( !strColorOut.isEmpty() )
      addOutput(strColorOut);
  }

}



void ShaderGenerator::initFragmentShaderIO(const ShaderGenDesc* _desc)
{

  QString inputShader = "Vertex";

  if ( _desc->geometryShader )
    inputShader = "Geometry";


  if (_desc->textured)
    addInput("vec2 out"+inputShader+"TexCoord");

  addInput("vec4 out"+inputShader+"PosCS");

  QString strColorIn = "";

  if (_desc->shadeMode == SG_SHADE_FLAT)
    addStringToList("vec4 out"+inputShader+"Color", &inputs_, "flat in ", ";");
  else
  {
    if (_desc->shadeMode == SG_SHADE_GOURAUD ||
      _desc->vertexColors)
      strColorIn = "vec4 out"+inputShader+"Color";
  }

  if (strColorIn.size())
    addInput(strColorIn);


  if (_desc->shadeMode == SG_SHADE_PHONG)
  {
    addInput("vec3 out"+inputShader+"Normal");
    addInput("vec4 out"+inputShader+"PosVS");
  }

  addOutput("vec4 outFragment");
}




void ShaderGenerator::initDefaultUniforms()
{
  addUniform("mat4 g_mWVP" , "  // Projection * Modelview");       // Transforms directly from Object space to NDC
  addUniform("mat4 g_mWV" , "   // Modelview matrix");             // Modelview transforms from Object to World to View coordinates
  addUniform("mat3 g_mWVIT" , " // Modelview inverse transposed"); // Modelview inverse transposed, transforms from view across World into Object coordinates
  addUniform("mat4 g_mP", "     // Projection matrix");            // Projection Matrix

  addUniform("vec3 g_vCamPos");
  addUniform("vec3 g_vCamDir");

  addUniform("vec3 g_cDiffuse");
  addUniform("vec3 g_cAmbient");
  addUniform("vec3 g_cEmissive");
  addUniform("vec3 g_cSpecular");
  addUniform("vec4 g_vMaterial");
}


#define ADDLIGHT(x) (sz.sprintf(x"_%d", lightIndex_), addUniform(sz))

void ShaderGenerator::addLight(int lightIndex_, ShaderGenLightType _light)
{
  QString sz;

  ADDLIGHT("vec3 g_cLightDiffuse");
  ADDLIGHT("vec3 g_cLightAmbient");
  ADDLIGHT("vec3 g_cLightSpecular");

  if (_light == SG_LIGHT_POINT ||
    _light == SG_LIGHT_SPOT)
  {
    ADDLIGHT("vec3 g_vLightPos");
    ADDLIGHT("vec3 g_vLightAtten");
  }

  if (_light == SG_LIGHT_DIRECTIONAL ||
    _light == SG_LIGHT_SPOT)
    ADDLIGHT("vec3 g_vLightDir");


  if (_light == SG_LIGHT_SPOT)
    ADDLIGHT("vec2 g_vLightAngleExp");
}



void ShaderGenerator::addStringToList(QString _str, 
                                      QStringList* _arr,
                                      QString _prefix,
                                      QString _postfix)
{
  // Construct the whole string
  QString tmp = _prefix + _str + _postfix;

  // normalize string
  //  remove tabs, double whitespace
  tmp = tmp.simplified();

  // avoid duplicates
  if (!_arr->contains(tmp))
    _arr->push_back(tmp);

}


void ShaderGenerator::addInput(QString _input)
{
  addStringToList(_input, &inputs_, "in ", ";");
}



void ShaderGenerator::addOutput(QString _output)
{
  addStringToList(_output, &outputs_, "out ", ";");
}


void ShaderGenerator::addDefine(QString _def)
{
  addStringToList(_def, &genDefines_, "#define ");
}




void ShaderGenerator::addUniform(QString _uniform, QString _comment)
{
  addStringToList(_uniform, &uniforms_, "uniform ", "; " + _comment );
}



void ShaderGenerator::addIOToCode(const QStringList& _cmds)
{
  QString it;
  foreach(it, _cmds)
  {
    code_.push_back(it);
    // append ; eventually

    if (!it.contains(";"))
      code_.back().append(";");
  }
}



void ShaderGenerator::buildShaderCode(QStringList* _pMainCode)
{
  code_.push_back(version_);

  // provide defines
  QString it;

  foreach(it, genDefines_)
    code_.push_back(it);

  // provide imports
  foreach(it, imports_)
    code_.push_back(it);

  // IO
  addIOToCode(inputs_);
  addIOToCode(outputs_);
  addIOToCode(uniforms_);

  // main function
  foreach(it, (*_pMainCode))
    code_.push_back(it);


}



void ShaderGenerator::addIncludeFile(QString _fileName)
{
  QFile file(_fileName);

  if (file.open(QIODevice::ReadOnly | QIODevice::Text))
  {
    QTextStream fileStream(&file);

    while (!fileStream.atEnd())
    {
      QString tmpLine = fileStream.readLine();

      imports_.push_back(tmpLine.simplified());
    }
  }

}



void ShaderGenerator::saveToFile(const char* _fileName)
{
  QFile file(_fileName);
  if (file.open(QIODevice::WriteOnly | QIODevice::Text))
  {
    QTextStream fileStream(&file);

    QString it;
    foreach(it, code_)
      fileStream << it << '\n';
  }
}



const QStringList& ShaderGenerator::getShaderCode()
{
  return code_;
}




QString ShaderProgGenerator::shaderDir_;
QStringList ShaderProgGenerator::lightingCode_;

ShaderProgGenerator::ShaderProgGenerator(const ShaderGenDesc* _desc,
                                         unsigned int _usage)
: vertex_(0), geometry_(0), fragment_(0), usage_(_usage)
{
  if (shaderDir_.isEmpty())
    std::cout << "error: call ShaderProgGenerator::setShaderDir() first!" << std::endl;
  else
  {
    desc_ = *_desc;

    // We need at least version 2.0 or higher to support geometry shaders
    QGLFormat::OpenGLVersionFlags flags = QGLFormat::openGLVersionFlags();
    desc_.geometryShader &= flags.testFlag(QGLFormat::OpenGL_Version_3_2);

    loadLightingFunctions();

    generateShaders();
  }
}

ShaderProgGenerator::~ShaderProgGenerator(void)
{
  delete vertex_;
  delete fragment_;
}



void ShaderProgGenerator::loadStringListFromFile(QString _fileName, QStringList* _out)
{
  QFile file(_fileName);

  file.open(QIODevice::ReadOnly | QIODevice::Text);

  if (!file.isReadable())
    std::cout << "error: file missing -> \"" << (const char*)_fileName.toAscii() << "\"" << std::endl;

  else
  {
    QTextStream filestream(&file);

    while (!filestream.atEnd())
    {
      QString szLine = filestream.readLine();
      _out->push_back(szLine.trimmed());
    }
  }
}


void ShaderProgGenerator::loadLightingFunctions()
{
  if (lightingCode_.size()) return;

  // load shader code from file
  loadStringListFromFile(shaderDir_ + QDir::separator() + QString(LIGHTING_CODE_FILE), &lightingCode_);
}



void ShaderProgGenerator::initGenDefines(ShaderGenerator* _gen)
{
  switch (desc_.shadeMode)
  {
  case SG_SHADE_GOURAUD:
    _gen->addDefine("SG_GOURAUD 1"); break;
  case SG_SHADE_FLAT:
    _gen->addDefine("SG_FLAT 1"); break;
  case SG_SHADE_UNLIT:
    _gen->addDefine("SG_UNLIT 1"); break;
  case SG_SHADE_PHONG:
    _gen->addDefine("SG_PHONG 1"); break;

  default:
    std::cout << __FUNCTION__ << " -> unknown shade mode: " << desc_.shadeMode << std::endl;
  }

  if (desc_.textured)
    _gen->addDefine("SG_TEXTURED 1");

  if (desc_.vertexColors)
    _gen->addDefine("SG_VERTEX_COLOR 1");

  if (desc_.shadeMode != SG_SHADE_UNLIT)
    _gen->addDefine("SG_NORMALS 1");

  // # lights define
  QString strNumLights;
  strNumLights.sprintf("SG_NUM_LIGHTS %d", desc_.numLights);
  _gen->addDefine(strNumLights);

  // light types define
  const char* lightTypeNames[] = {"SG_LIGHT_DIRECTIONAL",
    "SG_LIGHT_POINT", "SG_LIGHT_SPOT"};

  for (int i = 0; i < 3; ++i)
    _gen->addDefine(lightTypeNames[i]);


  for (int i = 0; i < desc_.numLights; ++i)
  {
    QString strLightType;
    strLightType.sprintf("SG_LIGHT_TYPE_%d %s", i, lightTypeNames[desc_.lightTypes[i]]);
    _gen->addDefine(strLightType);
  }
}




void ShaderProgGenerator::buildVertexShader()
{
  delete vertex_;

  vertex_  = new ShaderGenerator();


//  vertex_->initDefaultVertexShaderIO();
  vertex_->initVertexShaderIO(&desc_);

  vertex_->initDefaultUniforms();

  vertex_->addUniform("float g_PointSize");


  // apply i/o modifiers
  for (int i = 0; i < numModifiers_; ++i)
  {
    if (usage_ & (1 << i))
      modifiers_[i]->modifyVertexIO(vertex_);
  }


  initGenDefines(vertex_);



  // IO

  // when to use vertex lights
  if (desc_.shadeMode == SG_SHADE_GOURAUD ||
    desc_.shadeMode == SG_SHADE_FLAT)
  {
    for (int i = 0; i < desc_.numLights; ++i)
      vertex_->addLight(i, desc_.lightTypes[i]);
  }


  // assemble main function
  QStringList mainCode;

  addLightingFunctions(&mainCode);

  if (!vertexTemplate_.size())
  {
    mainCode.push_back("void main()");
    mainCode.push_back("{");

    addVertexBeginCode(&mainCode);
    addVertexEndCode(&mainCode);

    mainCode.push_back("}");
  }
  else
  {
    // interpret loaded shader template:
    //  import #includes and replace SG_VERTEX_BEGIN/END markers

    QString it;
    foreach(it,vertexTemplate_)
    {
      if (!checkForIncludes(it, vertex_, getPathName(vertexShaderFile_)))
      {
        // str line is no include directive
        // check for SG_ markers

        if (it.contains("SG_VERTEX_BEGIN"))
          addVertexBeginCode(&mainCode);
        else
        {
          if (it.contains("SG_VERTEX_END"))
            addVertexEndCode(&mainCode);
          else
          {
            // no SG marker
            mainCode.push_back(it);
          }
        }

      }
    }

  }

  vertex_->buildShaderCode(&mainCode);

}


void ShaderProgGenerator::addVertexBeginCode(QStringList* _code)
{
  // size in pixel of rendered point-lists, set by user via uniform
  _code->push_back("gl_PointSize = g_PointSize;");

  _code->push_back("vec4 sg_vPosPS = g_mWVP * inPosition;");
  _code->push_back("vec4 sg_vPosVS = g_mWV * inPosition;");
  _code->push_back("vec3 sg_vNormalVS = vec3(0.0, 1.0, 0.0);");
  _code->push_back("vec2 sg_vTexCoord = vec2(0.0, 0.0);");
  _code->push_back("vec4 sg_cColor = vec4(g_cEmissive, ALPHA);");

  if (desc_.shadeMode != SG_SHADE_UNLIT)
    _code->push_back("sg_vNormalVS = normalize(g_mWVIT * inNormal);");

  if (desc_.textured)
    _code->push_back("sg_vTexCoord = inTexCoord;");

  if (desc_.vertexColors)
    _code->push_back("sg_cColor = inColor;");

  if (desc_.shadeMode == SG_SHADE_GOURAUD ||
    desc_.shadeMode == SG_SHADE_FLAT)
  {
    // add lighting code here

    addLightingCode(_code);
  }



  // apply modifiers
  for (int i = 0; i < numModifiers_; ++i)
  {
    if (usage_ & (1 << i))
      modifiers_[i]->modifyVertexBeginCode(_code);
  }
}


void ShaderProgGenerator::addVertexEndCode(QStringList* _code)
{
  _code->push_back("gl_Position = sg_vPosPS;");
  _code->push_back("outVertexPosCS = sg_vPosPS;");

  if (desc_.textured)
    _code->push_back("outVertexTexCoord = sg_vTexCoord;");

  if (desc_.shadeMode == SG_SHADE_GOURAUD ||
    desc_.shadeMode == SG_SHADE_FLAT ||
    desc_.vertexColors)
    _code->push_back("outVertexColor = sg_cColor;");

  if (desc_.shadeMode == SG_SHADE_PHONG)
  {
    _code->push_back("outVertexNormal = sg_vNormalVS;");
    _code->push_back("outVertexPosVS  = sg_vPosVS;");
  }



  // apply modifiers
  for (int i = 0; i < numModifiers_; ++i)
  {
    if (usage_ & (1 << i))
      modifiers_[i]->modifyVertexEndCode(_code);
  }
}


int ShaderProgGenerator::checkForIncludes(QString _str, ShaderGenerator* _gen, QString _includePath)
{
  if (_str.contains("#include "))
  {
    QString strIncludeFile = _str.remove("#include ").remove('\"').remove('<').remove('>').trimmed();

    if (strIncludeFile.isEmpty())
      std::cout << "wrong include syntax: " << (const char*)_str.toAscii() << std::endl;
    else
    {
      QString fullPathToIncludeFile = _includePath + QDir::separator() + strIncludeFile;

      _gen->addIncludeFile(fullPathToIncludeFile);
    }

    return 1;
  }

  return 0;
}

void ShaderProgGenerator::buildGeometryShader()
{

  std::cerr << "TODO : buildGeometryShader" << std::endl;

  delete geometry_;

  // Only build a geometry shader if enabled
  if ( !desc_.geometryShader )
    return;

  geometry_  = new ShaderGenerator();


  geometry_->initGeometryShaderIO(&desc_);


  geometry_->initDefaultUniforms();


  // apply i/o modifiers
  for (int i = 0; i < numModifiers_; ++i)
  {
    if (usage_ & (1 << i))
      modifiers_[i]->modifyGeometryIO(fragment_);
  }


//  initGenDefines(fragment_);
//
//
//
//  // io
//
//  // when to use fragment lights
//  if (desc_.shadeMode == SG_SHADE_PHONG)
//  {
//    for (int i = 0; i < desc_.numLights; ++i)
//      fragment_->addLight(i, desc_.lightTypes[i]);
//  }
//
//

  // assemble main function
  QStringList mainCode;

//  addLightingFunctions(&mainCode);
//
//
  if (!geometryTemplate_.size())
  {
    mainCode.push_back("void main()");
    mainCode.push_back("{");

    addGeometryBeginCode(&mainCode);
    addGeometryEndCode(&mainCode);

    mainCode.push_back("}");
  }
  else
  {
    // interpret loaded shader template:
    //  import #includes and replace SG_GEOMETRY_BEGIN/END markers
    QString it;
    foreach(it,geometryTemplate_)
    {
      if (!checkForIncludes(it, geometry_, getPathName(geometryShaderFile_)))
      {
        // str line is no include directive
        // check for SG_ markers

        if (it.contains("SG_GEOMETRY_BEGIN"))
          addFragmentBeginCode(&mainCode);
        else
        {
          if (it.contains("SG_GEOMETRY_END"))
            addGeometryEndCode(&mainCode);
          else
          {
            // no SG marker
            mainCode.push_back(it);
          }
        }

      }


    }

  }

  geometry_->buildShaderCode(&mainCode);
}


void ShaderProgGenerator::addGeometryBeginCode(QStringList* _code)
{
  std::cerr << "TODO : addGeometryBeginCode" << std::endl;

//  // support for projective texture mapping
//  _code->push_back("vec2 sg_vScreenPos = outPosCS.xy / outPosCS.w * 0.5 + vec2(0.5, 0.5);");
//
//  _code->push_back("vec4 sg_cColor = vec4(g_cEmissive, ALPHA);");
//
//  if (desc_.shadeMode == SG_SHADE_GOURAUD ||
//    desc_.shadeMode == SG_SHADE_FLAT ||
//    desc_.vertexColors)
//    _code->push_back("sg_cColor = outColor;");
//
//
//  if (desc_.shadeMode == SG_SHADE_PHONG)
//  {
//    _code->push_back("vec4 sg_vPosVS = outPosVS;");
//    _code->push_back("vec3 sg_vNormalVS = outNormal;");
//
//    addLightingCode(_code);
//  }
//
//  if (desc_.textured)
//  {
//    _code->push_back("vec4 sg_cTex = texture(g_Texture0, outTexCoord);");
//    _code->push_back("sg_cColor *= sg_cTex;");
//  }
//
//
  // apply modifiers
  for (int i = 0; i < numModifiers_; ++i)
  {
    if (usage_ & (1 << i))
      modifiers_[i]->modifyGeometryBeginCode(_code);
  }
}

void ShaderProgGenerator::addGeometryEndCode(QStringList* _code)
{
  std::cerr << "TODO : addGeometryEndCode" << std::endl;

//  _code->push_back("outFragment = sg_cColor;");
//
  // apply modifiers
  for (int i = 0; i < numModifiers_; ++i)
  {
    if (usage_ & (1 << i))
      modifiers_[i]->modifyGeometryEndCode(_code);
  }
}


void ShaderProgGenerator::buildFragmentShader()
{
  delete fragment_;

  fragment_  = new ShaderGenerator();


  fragment_->initFragmentShaderIO(&desc_);


  fragment_->initDefaultUniforms();


  // texture sampler id
  if (desc_.textured)
    fragment_->addUniform("sampler2D g_Texture0");

  // apply i/o modifiers
  for (int i = 0; i < numModifiers_; ++i)
  {
    if (usage_ & (1 << i))
      modifiers_[i]->modifyFragmentIO(fragment_);
  }


  initGenDefines(fragment_);



  // io

  // when to use fragment lights
  if (desc_.shadeMode == SG_SHADE_PHONG)
  {
    for (int i = 0; i < desc_.numLights; ++i)
      fragment_->addLight(i, desc_.lightTypes[i]);
  }

  // assemble main function
  QStringList mainCode;

  addLightingFunctions(&mainCode);


  if (!fragmentTemplate_.size())
  {
    mainCode.push_back("void main()");
    mainCode.push_back("{");

    addFragmentBeginCode(&mainCode);
    addFragmentEndCode(&mainCode);

    mainCode.push_back("}");
  }
  else
  {
    // interpret loaded shader template:
    //  import #includes and replace SG_VERTEX_BEGIN/END markers
    QString it;
    foreach(it,fragmentTemplate_)
    {
      if (!checkForIncludes(it, fragment_, getPathName(fragmentShaderFile_)))
      {
        // str line is no include directive
        // check for SG_ markers

        if (it.contains("SG_FRAGMENT_BEGIN"))
          addFragmentBeginCode(&mainCode);
        else
        {
          if (it.contains("SG_FRAGMENT_END"))
            addFragmentEndCode(&mainCode);
          else
          {
            // no SG marker
            mainCode.push_back(it);
          }
        }

      }

      
    }

  }



  fragment_->buildShaderCode(&mainCode);
}


void ShaderProgGenerator::addFragmentBeginCode(QStringList* _code)
{

  QString inputShader = "Vertex";

  if ( desc_.geometryShader )
    inputShader = "Geometry";

  // support for projective texture mapping
  _code->push_back("vec2 sg_vScreenPos = out" + inputShader + "PosCS.xy / out" + inputShader + "PosCS.w * 0.5 + vec2(0.5, 0.5);");

  _code->push_back("vec4 sg_cColor = vec4(g_cEmissive, ALPHA);");

  if (desc_.shadeMode == SG_SHADE_GOURAUD ||
      desc_.shadeMode == SG_SHADE_FLAT    ||
      desc_.vertexColors)
  {
    _code->push_back("sg_cColor = out" + inputShader + "Color;");
  }


  if (desc_.shadeMode == SG_SHADE_PHONG)
  {
    _code->push_back("vec4 sg_vPosVS = out" + inputShader + "PosVS;");
    _code->push_back("vec3 sg_vNormalVS = out" + inputShader + "Normal;");

    addLightingCode(_code);
  }

  if (desc_.textured)
  {
    _code->push_back("vec4 sg_cTex = texture(g_Texture0, out" + inputShader + "TexCoord);");
    _code->push_back("sg_cColor *= sg_cTex;");
  }

  
  // apply modifiers
  for (int i = 0; i < numModifiers_; ++i)
  {
    if (usage_ & (1 << i))
      modifiers_[i]->modifyFragmentBeginCode(_code);
  }
}

void ShaderProgGenerator::addFragmentEndCode(QStringList* _code)
{
  _code->push_back("outFragment = sg_cColor;");

  // apply modifiers
  for (int i = 0; i < numModifiers_; ++i)
  {
    if (usage_ & (1 << i))
      modifiers_[i]->modifyFragmentEndCode(_code);
  }
}



void ShaderProgGenerator::addLightingCode(QStringList* _code)
{
  QString buf;
  
  for (int i = 0; i < desc_.numLights; ++i)
  {
    ShaderGenLightType lgt = desc_.lightTypes[i];


    switch (lgt)
    {
    case SG_LIGHT_DIRECTIONAL:
      buf.sprintf("sg_cColor.xyz += LitDirLight(sg_vPosVS.xyz, sg_vNormalVS, g_vLightDir_%d,  g_cLightAmbient_%d,  g_cLightDiffuse_%d,  g_cLightSpecular_%d);", i, i, i, i);
      break;

    case SG_LIGHT_POINT:
      buf.sprintf("sg_cColor.xyz += LitPointLight(sg_vPosVS.xyz, sg_vNormalVS,  g_vLightPos_%d,  g_cLightAmbient_%d,  g_cLightDiffuse_%d,  g_cLightSpecular_%d,  g_vLightAtten_%d);", i, i, i, i, i);
      break;

    case SG_LIGHT_SPOT:
      buf.sprintf("sg_cColor.xyz += LitSpotLight(sg_vPosVS.xyz,  sg_vNormalVS,  g_vLightPos_%d,  g_vLightDir_%d,  g_cLightAmbient_%d,  g_cLightDiffuse_%d,  g_cLightSpecular_%d,  g_vLightAtten_%d,  g_vLightAngleExp_%d);", i, i, i, i, i, i, i);
      break;

    default: break;
    }

    _code->push_back(buf);
  }

}



void ShaderProgGenerator::addLightingFunctions(QStringList* _code)
{
  QString it;
  foreach(it,lightingCode_)
    _code->push_back(it);
}

void ShaderProgGenerator::generateShaders()
{
  loadShaderTemplateFromFile();
  buildVertexShader();
  buildGeometryShader();
  buildFragmentShader();
}


const QStringList& ShaderProgGenerator::getVertexShaderCode()
{
  return vertex_->getShaderCode();
}

const QStringList& ShaderProgGenerator::getGeometryShaderCode()
{
  return geometry_->getShaderCode();
}

const QStringList& ShaderProgGenerator::getFragmentShaderCode()
{
  return fragment_->getShaderCode();
}


void ShaderProgGenerator::saveVertexShToFile(const char* _fileName)
{
  vertex_->saveToFile(_fileName);
}

void ShaderProgGenerator::saveGeometryShToFile(const char* _fileName)
{
  geometry_->saveToFile(_fileName);
}

void ShaderProgGenerator::saveFragmentShToFile(const char* _fileName)
{
  fragment_->saveToFile(_fileName);
}


void ShaderProgGenerator::loadShaderTemplateFromFile()
{
  if (!desc_.vertexTemplateFile.isEmpty())
    loadStringListFromFile(desc_.vertexTemplateFile, &vertexTemplate_);
  if (!desc_.fragmentTemplateFile.isEmpty())
    loadStringListFromFile(desc_.fragmentTemplateFile, &fragmentTemplate_);
  if (!desc_.geometryTemplateFile.isEmpty())
    loadStringListFromFile(desc_.geometryTemplateFile, &geometryTemplate_);

  vertexShaderFile_   = desc_.vertexTemplateFile;
  geometryShaderFile_ = desc_.geometryTemplateFile;
  fragmentShaderFile_ = desc_.fragmentTemplateFile;

}

QString ShaderProgGenerator::getPathName(QString _strFileName)
{
  QFileInfo fileInfo(_strFileName);
  return fileInfo.absolutePath();
}

void ShaderProgGenerator::setShaderDir( QString _dir )
{
  shaderDir_ = _dir;
}

unsigned int ShaderProgGenerator::registerModifier( ShaderModifier* _modifier )
{
  if (!_modifier) return 0;

  // redundancy check
  for (unsigned int i = 0; i < 32; ++i)
  {
    if (modifiers_[i] == _modifier) 
      return i;
  }

  if (numModifiers_ == 32) 
    return 0;

  modifiers_[numModifiers_++] = _modifier;

  _modifier->modifierID_ = (unsigned int)numModifiers_;
  return _modifier->modifierID_;
}


//=============================================================================

ShaderModifier::ShaderModifier( void )
: modifierID_(0)
{}

ShaderModifier::~ShaderModifier( void )
{}

//=============================================================================


QString ShaderGenDesc::toString() const
{
  // mapping (int)ShaderGenMode -> string
  const char* shadeModeString[] = 
  {
    "SG_SHADE_UNLIT",
    "SG_SHADE_FLAT",
    "SG_SHADE_GOURAUD",
    "SG_SHADE_PHONG"
  };

  QString res;
  QTextStream resStrm(&res);

  resStrm << "shaderDesc.numLights: " << numLights;

  if (numLights)
  {
    resStrm << "\nshaderDesc.lightTypes[]: {";

    for (int i = 0; i < numLights; ++i)
    {
      switch (lightTypes[i]) 
      {
      case SG_LIGHT_DIRECTIONAL: resStrm << "DIRECTIONAL"; break;
      case SG_LIGHT_POINT: resStrm << "POINT"; break;
      case SG_LIGHT_SPOT: resStrm << "SPOT"; break;
      default: resStrm << "UNDEFINED"; break;
      }

      if (i + 1 < numLights)
        resStrm << ", ";
      else
        resStrm << "}";
    }
  }


  resStrm << "\nshaderDesc.shadeMode: " << shadeModeString[shadeMode];
  resStrm << "\nshaderDesc.vertexColors: " << vertexColors;
  resStrm << "\nshaderDesc.textured: " << textured;

  if (!vertexTemplateFile.isEmpty())
    resStrm << "\nshaderDesc.vertexTemplateFile: " << vertexTemplateFile;

  if (!geometryTemplateFile.isEmpty())
    resStrm << "\nshaderDesc.geometryTemplateFile: " << geometryTemplateFile;

  if (!fragmentTemplateFile.isEmpty())
    resStrm << "\nshaderDesc.fragmentTemplateFile: " << fragmentTemplateFile;

  return res;
}


} // namespace ACG
//=============================================================================
