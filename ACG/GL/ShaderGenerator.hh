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
 *   $Revision: 16301 $                                                       *
 *   $Author: moebius $                                                      *
 *   $Date: 2013-02-13 16:16:24 +0800 (Wed, 13 Feb 2013) $                   *
 *                                                                           *
\*===========================================================================*/

#pragma once

#include <QStringList>
#include <QString>
#include <string>
#include <list>
#include <ACG/Config/ACGDefines.hh>


namespace ACG
{


// #define MAX_SHADER_INPUT_UNITS 32
// #define MAX_SHADER_CONSTANTS 0x200
// #define MAX_SHADER_GEN_DEFINES 0x100
#define SG_MAX_SHADER_LIGHTS 8

enum ShaderGenLightType
{
  SG_LIGHT_DIRECTIONAL = 0,
  SG_LIGHT_POINT,
  SG_LIGHT_SPOT,
  SG_LIGHT_FORCE_DWORD = 0xFFFFFFFF
};

enum ShaderGenShadeMode
{
  SG_SHADE_UNLIT = 0,
  SG_SHADE_FLAT,
  SG_SHADE_GOURAUD,
  SG_SHADE_PHONG,
  SG_SHADE_FORCE_DWORD = 0xFFFFFFFF
};

enum GeometryShaderInput {
  SG_GEOMETRY_IN_TRIANGLES = 0,
  SG_GEOMETRY_IN_TRIANGLES_ADJACENCY,
  SG_GEOMETRY_IN_LINES,
  SG_GEOMETRY_IN_LINES_ADJACENCY,
  SG_GEOMETRY_IN_POINTS
};

enum GeometryShaderOutput {
  SG_GEOMETRY_OUT_TRIANGLE_STRIP = 0,
  SG_GEOMETRY_OUT_LINE_STRIP,
  SG_GEOMETRY_OUT_POINTS
};

class ShaderGenDesc
{

public:
  ShaderGenDesc() :
    numLights(0),
    shadeMode(SG_SHADE_UNLIT),
    vertexColors(false),
    textured(false),
    vertexTemplateFile(""),
    geometryTemplateFile(""),
    fragmentTemplateFile(""),
    geometryShader(false),
    geometryShaderInput(SG_GEOMETRY_IN_TRIANGLES),
    geometryShaderOutput(SG_GEOMETRY_OUT_TRIANGLE_STRIP),
    geometryShaderMaxOutputPrimitives(3)
  {
    for ( unsigned int i = 0 ; i < SG_MAX_SHADER_LIGHTS ; ++i)
      lightTypes[i] = SG_LIGHT_DIRECTIONAL;

  }

//  In case, something crashes with the light types, try this hammer ;-)
//  const ShaderGenDesc& operator= (const ShaderGenDesc& _rhs) {
//
//    numLights                         = _rhs.numLights;
//
//    std::copy(_rhs.lightTypes,_rhs.lightTypes+SG_MAX_SHADER_LIGHTS,lightTypes);
//
//    shadeMode                         = _rhs.shadeMode;
//    vertexColors                      = _rhs.vertexColors;
//    textured                          = _rhs.textured;
//    vertexTemplateFile                = _rhs.vertexTemplateFile;
//    geometryTemplateFile              = _rhs.geometryTemplateFile;
//    fragmentTemplateFile              = _rhs.fragmentTemplateFile;
//    geometryShader                    = _rhs.geometryShader;
//    geometryShaderInput               = _rhs.geometryShaderInput;
//    geometryShaderOutput              = _rhs.geometryShaderOutput;
//    geometryShaderMaxOutputPrimitives = _rhs.geometryShaderMaxOutputPrimitives;
//
//    return *this;
//  }


  int numLights;
  ShaderGenLightType lightTypes[SG_MAX_SHADER_LIGHTS];

  ShaderGenShadeMode shadeMode;

  bool vertexColors;
  bool textured;

  // optionally specify shader template file names
  QString vertexTemplateFile;
  QString geometryTemplateFile;
  QString fragmentTemplateFile;

  /// convert ShaderGenDesc to string format for debugging
  QString toString() const;

  /// Flag setting, if we want a geometry shader
  bool geometryShader;

  /// Defines what kind of primitives are the input by the geometry shader
  GeometryShaderInput geometryShaderInput;

  /// Defines what kind of primitives are created by the geometry shader
  GeometryShaderOutput geometryShaderOutput;

  /// Defines the maximal number of primitives generated by the geometry shader
  int geometryShaderMaxOutputPrimitives;

};


/** \page ShaderGenerator_page Shader Generator

\section ShaderGenerator_auto_shader_uniforms Automatically generated Shader Uniforms

\subsection Matrix
\code
  mat4 g_mWVP  - world-view-projection transform
  mat4 g_mWV   - world-view transform
  mat4 g_mWVIT - inverse transpose of world view matrix
  mat4 g_mP    - projection matrix
\endcode

\subsection Color
\code
  vec3 g_cDiffuse - diffuse color
  vec3 g_cAmbient - ambient color
  vec3 g_cEmissive - emissive color
  vec3 g_cSpecular - specular color
  vec4 g_vMaterial - vec4(shininess, alpha, unused, unused)
\endcode


\subsection Lighting

\code
  // light parameters denoted by zero-based index i
  vec3 g_cLightDiffuse_i   - diffuse color
  vec3 g_cLightAmbient_i   - ambient color
  vec3 g_cLightSpecular_i  - specular color
  vec3 g_vLightPos_i       - position in view space (for point and spot lights only)
  vec3 g_vLightAtten_i     - [constant, linear, quadratic] attenuation factors (for point and spot lights only)
  vec3 g_vLightDir_i       - light direction in view space (for spot and directional lights only)
  vec2 g_vLightAngleExp_i  - [cos(spotCutOffAngle), spot exponent] (for spot lights only)
\endcode

\subsection Texturing
\code
  sampler2D g_Texture0     - texture sampler (if textured is enabled in ShaderGenDesc)
\endcode



\section ShaderGenerator_auto_shader_inout Automatically generated shader input/output:

\subsection  ShaderGenerator_vertex_shader_io Vertex shader IO

\code
  in vec4 inPosition - vertex position in model space

  in vec3 inNormal   - vertex normal (only if ShaderGenDesc.shadeMode != unlit)
  in vec4 inColor    - vertex color (only if ShaderGenDesc.vertexColors == true)
  in vec2 inTexCoord - texture coordinate (only if ShaderGenDesc.textured == true)

  out vec4 outPosCS  - position in clip space
  out vec3 outNormal - normal in view space (only if ShaderGenDesc.shadeMode == phong)
  out vec4 outPosVS  - position in view space (only if ShaderGenDesc.shadeMode == phong)
  out vec4 outColor  - vertex color after lighting (only if ShaderGenDesc.shadeMode == flat or gouraud)
  out vec2 outTexCoord - texture coordinate (only if ShaderGenDesc.textured == true)

  // insert input/outputs added from modifiers here
\endcode

\subsection ShaderGenerator_fragment_shader_io Fragment shader IO

See vertex shader outputs for fragment inputs.
\code
  out vec4 outFragment - fragment color

  // insert input/outputs added from modifiers here
\endcode


\section ShaderGenerator_auto_shader_defines Automatically generated shader defines
These come in handy when you need to keep compatibility with custom shaders.

Depending on the shademode of ShaderGenDesc, exactly one of the following defines is active.
 - SG_GOURAUD
 - SG_FLAT
 - SG_UNLIT
 - SG_PHONG


Additional defines:
\code
SG_NORMALS      // defined if vertex normals are available
SG_TEXTURE      // defined if ShaderGenDesc.textured     == true
SG_VERTEX_COLOR // defined if ShaderGenDesc.vertexColors == true

\endcode

Lighting:
\code
 SG_NUM_LIGHTS   // number of lights

  //for each light i:
  SG_LIGHT_TYPE_i // Determine the type of light i; set to one of {SG_LIGHT_DIRECTIONAL, SG_LIGHT_POINT, SG_LIGHT_SPOT}

  // Example:
  #define SG_LIGHT_TYPE_0 SG_LIGHT_DIRECTIONAL
  #define SG_LIGHT_TYPE_1 SG_LIGHT_DIRECTIONAL
  #define SG_LIGHT_TYPE_2 SG_LIGHT_POINT
\endcode

\section ShaderGenerator_general_vertex_shader_structure Vertex shader generation structure

\code
void main()
{
  vec4 sg_vPosPS    = g_mWVP * inPosition;
  vec4 sg_vPosVS    = g_mWV  * inPosition;
  vec3 sg_vNormalVS = vec3(0.0, 1.0, 0.0);
  vec2 sg_vTexCoord = vec2(0.0, 0.0);
  vec4 sg_cColor    = vec4(g_cEmissive, ALPHA);

#if normals available
  sg_vNormalVS = g_mWVIT * inNormal;

#if textured
  sg_vTexCoord = inTexCoord;

#if vertexcolors
  sg_cColor = inColor;


#if vertex-lighting enabled
  lighting code, save lit color in sg_cColor


  // -------------------------------------------------------------------------
  // begin customized code
  // - insert registered begin-code modifiers, that ideally operate on generated sg_* variables
  // - loaded code from template file is added here
  // make sure to use #ifdef #endif if you make use of conditional inputs such as normals, texcoords..
  // end of customized code
  // -------------------------------------------------------------------------
  
  gl_Position = sv_vPosPS;
  outPosCS = sg_vPosPS;

#if textured
  outTexCoord = sg_vTexCoord;

#if vertex-lighting
  outColor = sg_cColor;

#if fragment-lighting
  outNormal = sg_vNormalVS;
  outPosVS = sg_vPosVS;

  // end-code modifiers are added here
}

\endcode


---------------------------------------------------------------------------------------

\section ShaderGenerator_general_fragment_shader_structure Fragment shader generation structure


\code
void main()
{

  // compute screen-projected coordinates, useful for various post-processing effects
  vec2 sg_vScreenPos = outPosCS.xy / outPosCS.w * 0.5 + vec2(0.5, 0.5);
  
  vec4 sg_cColor = vec4(g_cEmisive, ALPHA);

#if vertex-lighting
  sg_cColor = outColor;

#if fragment lighting
  vec4 sg_vPosVS = outPosVS;
  vec3 sg_vNormalVS = outNormal;
  lighting code here, save color to sg_cColor


#if textured
  vec4 sg_cTex = texture(g_Texture0, outTexCoord);
  sg_cColor *= sg_cTex;

  // -------------------------------------------------------------------------
  // begin customized code
  // - insert registered begin-code modifiers, that ideally operate on generated sg_* variables
  // - loaded code from template file is added here
  // make sure to use #ifdef #endif if you make use of conditional inputs such as normals, texcoords..
  // end of customized code
  // -------------------------------------------------------------------------

  outFragment = sg_cColor;

  // end-code modifiers are added here
}
\endcode

*/

/**
The ShaderGenerator is used to collect shader io, uniforms, defines and includes.

The shader main-function is not generated here and must be provided
as a parameter to the buildShaderCode function.
*/
class ACGDLLEXPORT ShaderGenerator
{
public:

  ShaderGenerator();
  virtual ~ShaderGenerator();

  /** \brief Imports another shader, same as \#include
  */
  void addIncludeFile(QString _fileName);

  /** \brief Adds fitting vertex shader io for a given description
  */
  void initVertexShaderIO(const ShaderGenDesc* _desc);
  
  /** \brief Adds fitting vertex shader io for a given description
  */
  void initGeometryShaderIO(const ShaderGenDesc* _desc);

  /** \brief Adds fitting fragment shader io for a given description
  */
  void initFragmentShaderIO(const ShaderGenDesc* _desc);

  /** \brief Adds frequently used uniform parameters
   *
   * Adds frequently used uniform parameters like:
   *  - world, view, projection matrices
   *  - cam pos, view dir
   *  - per object material names: g_cDiffuse, g_cAmbient...
  */
  void initDefaultUniforms();

  /** \brief Add one GLSL input specifier
   *
   * Stores string pointer only
   * Example:
   * \code
   *   in vec4 inPosition;
   * \endcode
  */
  void addInput(QString _input);

  /** \brief Add one GLSL output specifier
   *
   * Stores string pointer only
   * Example:
   * \code
   *   out vec4 inPosition;
   *   \endcode
   */
  void addOutput(QString _output);

  /** \brief Add one GLSL uniform specifier
   *
   * Stores string pointer only
   * Example:
   * \code
   *   uniform sampler2D sampAmbient;
   * \endcode
   */
  void addUniform(QString _uniform, QString _comment = "");

  /** \brief Add one define
   *
   * Example:
   * \code
   *   #define SG_GOURAUD 1
   * \endcode
   */
  void addDefine(QString _uniform);


  /** \brief Add a light description to shader:
  */
  void addLight(int lightIndex_, ShaderGenLightType _light);

  /** \brief Shader assembly function
  */
  void buildShaderCode(QStringList* _pMainCode);

  /** \brief Get result of buildShaderCode
  */
  const QStringList& getShaderCode();

  /** \brief Save generated shader code to text file
   *
   * @param _fileName Where to save
  */
  void saveToFile(const char* _fileName);

private:

  /** aborts, if string already present
   *  prefix, postfix are very primitive,
   *  only checks for occurrence disregard locations
   */
  void addStringToList(QString _str, QStringList* _list, QString _prefix = "", QString _postfix = "");

  /** Adds command lines to the shader code.
  Eventually appends missing ';'
  */
  void addIOToCode(const QStringList& _cmds);

  QStringList code_;


  /// glsl code imports (with \#include )
  QStringList imports_;

  QString version_;

  QStringList inputs_;
  QStringList outputs_;
  QStringList uniforms_;
  QStringList genDefines_;
};



/**
 *
 * A shader modifier can modify uniforms, in/outputs
 * and glsl code of vertex and fragment shaders.
 * This is useful for global effects like shadow mapping
 * and depth peeling, where only a little changes in code are necessary.
 *
 * Usage:
 *  -# Derive a new subclass of ShaderModifier and implement necessary modify functions.
 *  -# Allocate a static instance of your modifier and register it to ShaderProgGenerator to get it's modifier-ID
 *  -# Create ShaderProgGenerator with a bitwise combination of modifier IDs to activate them.
 *
 * Example:
 * \code
 *
 *   // First modifier
 *   class VertexShaderModifier1 : public ACG::ShaderModifier {
 *   public:
 *     void modifyVertexEndCode(QStringList* _code) {
 *       _code->push_back("// Vertex End Code Modifier begin");
 *       _code->push_back("<Some glsl code>  ");
 *       _code->push_back("// Vertex End Code Modifier end");
 *     }
 *
 *     static VertexShaderModifier1 instance;
 *   };
 *
 *   // Static instance required!
 *   VertexShaderModifier YarnVertexShaderModifier::instance;
 *
 *
 *   class VertexShaderModifier2 : public ACG::ShaderModifier {
 *   public:
 *     void modifyVertexEndCode(QStringList* _code) {
 *       _code->push_back("// Vertex End Code Modifier 2 begin");
 *       _code->push_back("<Some glsl code>  ");
 *       _code->push_back("// Vertex End Code Modifier 2 end");
 *     }
 *
 *     static VertexShaderModifier2 instance;
 *   };
 *
 *   VertexShaderModifier2 VertexShaderModifier2::instance;
 * \endcode
 *
 * To use the modifiers, you have to register them to the shader generator:
 * \code
 *  // Register the modifiers
 *  ACG::ShaderProgGenerator::registerModifier(&VertexShaderModifier::instance);
 *  ACG::ShaderProgGenerator::registerModifier(&VertexShaderModifier2::instance);
 *
 *  // Use them via the shader cache
 *  GLSL::Program* prog = ACG::ShaderCache::getInstance()->getProgram(&shDesc,(VertexShaderModifier::instance.getID() | VertexShaderModifier2::instance.getID() ));
 * \endcode
 */
class ACGDLLEXPORT ShaderModifier
{
  friend class ShaderProgGenerator;

public:
  ShaderModifier(void);
  virtual ~ShaderModifier(void);

  /** \brief Add your own inputs/outputs to the vertex shader.
  *
  * Your implementation may look like this:
  *
  * \code
  *   _shader->addInput("vec4 inTangent");
  *   _shader->addUniform("vec4 shaderParam");
  * \endcode
  *
  * @param _shader shader interface
  */
  virtual void modifyVertexIO(ShaderGenerator* _shader) {}

  /** \brief Append code the the vertex shader.
   *
   * Refer to the generation structure (\ref ShaderGenerator_page ) to see where
   * your code is added and which variables you can modify.
   * Use
   * \code
   *   _code->push_back("...");
   * \endcode
   * to insert your code here.
   *
   * @param _code string list of shader code.
  */
  virtual void modifyVertexBeginCode(QStringList* _code) {}

  /** \brief  Append code the the vertex shader
   *
   * Refer to the generation structure (\ref ShaderGenerator_page ) to see
   * where your code is added and which variables you can modify.
   * Use
   *
   * \code
   *   _code->push_back("...");
   * \endcode
   * to insert your code here
   *
   * @param _code string list of shader code.
   */
  virtual void modifyVertexEndCode(QStringList* _code) {}

  /** \brief Add your own inputs/outputs to the geometry shader.
   *
   * your implementation may look like this:
   *
   * \code
   * _shader->addInput("sampler2D depthSampler");
   * _shader->addUniform("vec4 shaderParam");
   * \endcode
   *
   * @param _shader shader interface
  */
  virtual void modifyGeometryIO(ShaderGenerator* _shader) {}

  /** \brief Append code the the geometry shader.
   *
   * Refer to the generation structure (\ref ShaderGenerator_page ) to see where
   * your code is added and which variables you can modify.
   * Use
   * \code
   *   _code->push_back("...");
   * \endcode
   * to insert your code here
   *
   * @param _code string list of shader code.
  */
  virtual void modifyGeometryBeginCode(QStringList* _code) {}

  /** \brief Append code the the geometry shader.
   *
   *  Refer to the generation structure (\ref ShaderGenerator_page )
   *  to see where your code is added and which variables you can modify.
   *  Use
   *  \code
   *    _code->push_back("...");
   *  \endcode
   *  to insert your code here.
   * @param _code string list of shader code.
  */
  virtual void modifyGeometryEndCode(QStringList* _code) {}


  /** \brief Add your own inputs/outputs to the fragment shader.
   *
   * your implementation may look like this:
   *
   * \code
   * _shader->addInput("sampler2D depthSampler");
   * _shader->addUniform("vec4 shaderParam");
   * \endcode
   *
   * @param _shader shader interface
  */
  virtual void modifyFragmentIO(ShaderGenerator* _shader) {}

  /** \brief Append code the the fragment shader.
   *
   * Refer to the generation structure (\ref ShaderGenerator_page ) to see where
   * your code is added and which variables you can modify.
   * Use
   * \code
   *   _code->push_back("...");
   * \endcode
   * to insert your code here
   *
   * @param _code string list of shader code.
  */
  virtual void modifyFragmentBeginCode(QStringList* _code) {}

  /** \brief Append code the the fragment shader.
   *
   *  Refer to the generation structure (\ref ShaderGenerator_page )
   *  to see where your code is added and which variables you can modify.
   *  Use
   *  \code
   *    _code->push_back("...");
   *  \endcode
   *  to insert your code here.
   * @param _code string list of shader code.
  */
  virtual void modifyFragmentEndCode(QStringList* _code) {}

  /** \brief Returns the modifier ID
   *
   * @return Id of the modifier
  */
  unsigned int getID() {return modifierID_;}

  operator unsigned int() const {return modifierID_;}

private:
  unsigned int modifierID_;
};


/**
ShaderProgGenerator is responsible for generating a matching pair of vertex and fragment shaders.
*/
class ACGDLLEXPORT ShaderProgGenerator
{
public:

  /**
  The shader directory has to be defined first before making use of the generator!
  For example: setShaderDir(OpenFlipper::Options::shaderDirStr())
  */
  static void setShaderDir(QString _dir);

  /** 
  @param _desc description-set of shader properties.
  @param _modifierFlags bitflag of modifier-IDs that should be used for the generation.
  */
  ShaderProgGenerator(const ShaderGenDesc* _desc, unsigned int _modifierFlags = 0);
  virtual ~ShaderProgGenerator(void);


  void saveVertexShToFile(const char* _fileName);
  void saveGeometryShToFile(const char* _fileName);
  void saveFragmentShToFile(const char* _fileName);

  /** \brief Returns generated vertex shader code
  */
  const QStringList& getVertexShaderCode();

  /** \brief Returns generated geometry shader code
  */
  const QStringList& getGeometryShaderCode();

  /** \brief Returns generated fragment shader code
  */
  const QStringList& getFragmentShaderCode();


  /** \brief Shader modifiers has to be registered before it can be used.
             They also must remain allocated for the rest of the applications runtime.
             Use a combination of modifier-IDs in the constructor of ShaderProgGen to active them.
  @param _modifier address of a modifier implementation
  @return modifier ID
  */
  static unsigned int registerModifier(ShaderModifier* _modifier);

  bool hasGeometryShader() { return desc_.geometryShader; };

private:

  /** \brief Loads external shader templates
  */
  void loadShaderTemplateFromFile();

  void generateShaders();

  void buildVertexShader();
  void buildGeometryShader();
  void buildFragmentShader();

  void addVertexBeginCode(QStringList* _code);
  void addVertexEndCode(QStringList* _code);

  void addGeometryBeginCode(QStringList* _code);
  void addGeometryEndCode(QStringList* _code);

  void addFragmentBeginCode(QStringList* _code);
  void addFragmentEndCode(QStringList* _code);

  /** \brief Adds lighting definition functions
   *
   * LitPointLight() ...
   */
  void addLightingFunctions(QStringList* _code);

  /** \brief Adds lighting function calls to code
   */
  void addLightingCode(QStringList* _code);

  /// returns path to _strFileName without last slash
  QString getPathName(QString _strFileName);

  /// checks if _str is an include directive
  /// eventually imports the included file to the specified generator
  int checkForIncludes(QString _str, ShaderGenerator* _gen, QString _includePath);

  /// provide generated defines to shader
  void initGenDefines(ShaderGenerator* _gen);

  static void loadLightingFunctions();

  static void loadStringListFromFile(QString _fileName, QStringList* _out);

  ShaderGenerator* vertex_;
  ShaderGenerator* geometry_;
  ShaderGenerator* fragment_;

  QStringList vertexTemplate_;
  QStringList geometryTemplate_;
  QStringList fragmentTemplate_;

  ShaderGenDesc   desc_;
  unsigned int usage_;


  /// registered shader modifier
  static int numModifiers_;
  static ShaderModifier* modifiers_[32];

  /// path + filename to shader templates
  QString vertexShaderFile_;
  QString geometryShaderFile_;
  QString fragmentShaderFile_;


  static QString shaderDir_;
  static QStringList lightingCode_;

  
};


//=============================================================================
} // namespace ACG
//=============================================================================
