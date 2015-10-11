//
// Direct3D 9 wrapper
// OpenGL parts
//


#include "precompile.h"

#define GL_GLEXT_PROTOTYPES

#include <list>
#include <new>

#ifdef _WIN32
#include <windows.h>
#endif

#include "GL/glcorearb.h"
#include "ltjs_d3d9_exception.h"
#include "ltjs_d3d9_id3d9_impl.h"
#include "ltjs_d3d9_wrapper.h"


// ===========================================
// Extenstion function prototypes and wrappers
//

namespace {


PFNGLACTIVETEXTUREPROC glActiveTexture_ = nullptr;
PFNGLATTACHSHADERPROC glAttachShader_ = nullptr;
PFNGLBINDBUFFERPROC glBindBuffer_ = nullptr;
PFNGLBUFFERDATAPROC glBufferData_ = nullptr;
PFNGLCOMPILESHADERPROC glCompileShader_ = nullptr;
PFNGLCREATEPROGRAMPROC glCreateProgram_ = nullptr;
PFNGLCREATESHADERPROC glCreateShader_ = nullptr;
PFNGLDELETEBUFFERSPROC glDeleteBuffers_ = nullptr;
PFNGLDELETEPROGRAMPROC glDeleteProgram_ = nullptr;
PFNGLDELETESHADERPROC glDeleteShader_ = nullptr;
PFNGLDETACHSHADERPROC glDetachShader_ = nullptr;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray_ = nullptr;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray_ = nullptr;
PFNGLGENBUFFERSPROC glGenBuffers_ = nullptr;
PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation_ = nullptr;
PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog_ = nullptr;
PFNGLGETPROGRAMIVPROC glGetProgramiv_ = nullptr;
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog_ = nullptr;
PFNGLGETSHADERIVPROC glGetShaderiv_ = nullptr;
PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation_ = nullptr;
PFNGLISPROGRAMPROC glIsProgram_ = nullptr;
PFNGLISSHADERPROC glIsShader_ = nullptr;
PFNGLLINKPROGRAMPROC glLinkProgram_ = nullptr;
PFNGLSHADERSOURCEPROC glShaderSource_ = nullptr;
PFNGLUNIFORM1IPROC glUniform1i_ = nullptr;
PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv_ = nullptr;
PFNGLUSEPROGRAMPROC glUseProgram_ = nullptr;
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer_ = nullptr;


} // namespace


GLAPI void APIENTRY glActiveTexture(
    GLenum texture)
{
    glActiveTexture_(
        texture);
}

GLAPI void APIENTRY glAttachShader(
    GLuint program,
    GLuint shader)
{
    glAttachShader_(
        program,
        shader);
}

GLAPI void APIENTRY glBindBuffer(
    GLenum target,
    GLuint buffer)
{
    glBindBuffer_(
        target,
        buffer);
}

GLAPI void APIENTRY glBufferData(
    GLenum target,
    GLsizeiptr size,
    const GLvoid* data,
    GLenum usage)
{
    glBufferData_(
        target,
        size,
        data,
        usage);
}

GLAPI void APIENTRY glCompileShader(
    GLuint shader)
{
    glCompileShader_(
        shader);
}

GLAPI GLuint APIENTRY glCreateProgram()
{
    return glCreateProgram_();
}

GLAPI GLuint APIENTRY glCreateShader(
    GLenum type)
{
    return glCreateShader_(
        type);
}

GLAPI void APIENTRY glDeleteBuffers(
    GLsizei n,
    const GLuint* buffers)
{
    glDeleteBuffers_(
        n,
        buffers);
}

GLAPI void APIENTRY glDeleteProgram(
    GLuint program)
{
    glDeleteProgram_(
        program);
}

GLAPI void APIENTRY glDeleteShader(
    GLuint shader)
{
    glDeleteShader_(
        shader);
}

GLAPI void APIENTRY glDetachShader(
    GLuint program,
    GLuint shader)
{
    glDetachShader_(
        program,
        shader);
}

GLAPI void APIENTRY glDisableVertexAttribArray(
    GLuint index)
{
    glDisableVertexAttribArray_(
        index);
}

GLAPI void APIENTRY glEnableVertexAttribArray(
    GLuint index)
{
    glEnableVertexAttribArray_(
        index);
}

GLAPI void APIENTRY glGenBuffers(
    GLsizei n,
    GLuint* buffers)
{
    glGenBuffers_(
        n,
        buffers);
}

GLAPI GLint APIENTRY glGetAttribLocation(
    GLuint program,
    const GLchar* name)
{
    return glGetAttribLocation_(
        program,
        name);
}

GLAPI void APIENTRY glGetProgramInfoLog(
    GLuint program,
    GLsizei bufSize,
    GLsizei* length,
    GLchar* infoLog)
{
    glGetProgramInfoLog_(
        program,
        bufSize,
        length,
        infoLog);
}

GLAPI void APIENTRY glGetProgramiv(
    GLuint program,
    GLenum pname,
    GLint* params)
{
    glGetProgramiv_(
        program,
        pname,
        params);
}

GLAPI void APIENTRY glGetShaderInfoLog(
    GLuint shader,
    GLsizei bufSize,
    GLsizei* length,
    GLchar* infoLog)
{
    glGetShaderInfoLog_(
        shader,
        bufSize,
        length,
        infoLog);
}

GLAPI void APIENTRY glGetShaderiv(
    GLuint shader,
    GLenum pname,
    GLint* params)
{
    glGetShaderiv_(
        shader,
        pname,
        params);
}

GLAPI GLint APIENTRY glGetUniformLocation(
    GLuint program,
    const GLchar* name)
{
    return glGetUniformLocation_(
        program,
        name);
}

GLAPI GLboolean APIENTRY glIsProgram(
    GLuint program)
{
    return glIsProgram_(
        program);
}

GLAPI GLboolean APIENTRY glIsShader(
    GLuint shader)
{
    return glIsShader_(
        shader);
}

GLAPI void APIENTRY glLinkProgram(
    GLuint program)
{
    glLinkProgram_(
        program);
}

GLAPI void APIENTRY glShaderSource(
    GLuint shader,
    GLsizei count,
    const GLchar* const* string,
    const GLint* length)
{
    glShaderSource_(
        shader,
        count,
        string,
        length);
}

GLAPI void APIENTRY glUniform1i(
    GLint location,
    GLint v0)
{
    glUniform1i_(
        location,
        v0);
}

GLAPI void APIENTRY glUniformMatrix4fv(
    GLint location,
    GLsizei count,
    GLboolean transpose,
    const GLfloat* value)
{
    glUniformMatrix4fv_(
        location,
        count,
        transpose,
        value);
}

GLAPI void APIENTRY glUseProgram(
    GLuint program)
{
    glUseProgram_(
        program);
}

GLAPI void APIENTRY glVertexAttribPointer(
    GLuint index,
    GLint size,
    GLenum type,
    GLboolean normalized,
    GLsizei stride,
    const GLvoid* pointer)
{
    glVertexAttribPointer_(
        index,
        size,
        type,
        normalized,
        stride,
        pointer);
}

//
// Extenstion function prototypes and wrappers
// ===========================================


namespace {


using Strings = std::list<std::string>;


template<typename T>
void ogl_get_symbol(
    const char* symbol_name,
    T& symbol,
    Strings& missing_symbols)
{
    symbol = ltjs::d3d9::SymbolToFunction<T>(::wglGetProcAddress(
        symbol_name));

    if (!symbol) {
        missing_symbols.push_back(symbol_name);
    }
}


std::string ogl_build_error_message(
    const Strings& symbols)
{
    if (symbols.empty()) {
        return std::string();
    }

    std::string message = "Missing OpenGL symbols:";

    for (const auto& symbol : symbols) {
        message += '\n';
        message += symbol;
    }

    return message;
}


} // namespace


namespace ltjs {
namespace d3d9 {


bool Wrapper::initialize_ogl()
{
    uninitialize_ogl();

    mode_ = Mode::ogl;

    return true;
}

bool Wrapper::preinitialize_ogl_context(
    HWND device_window)
{
    // Check window's properties
    //

    if (!device_window) {
        error_message_ = "Null device window.";
        return false;
    }

    auto class_style = ::GetClassLongPtrW(
        device_window,
        GCL_STYLE);

    if (class_style == 0) {
        error_message_ = "Failed to get class style.";
        return false;
    }

    if ((class_style & CS_OWNDC) == 0) {
        error_message_ = "Windows does not have unique device context.";
        return false;
    }


    // Get device context
    //

    auto device_context = ::GetDC(
        device_window);

    if (!device_context) {
        error_message_ = "Failed to get device context.";
        return false;
    }


    // Choose pixel format index
    //

    DWORD flags =
        PFD_DRAW_TO_WINDOW |
        PFD_SUPPORT_OPENGL |
        PFD_DOUBLEBUFFER;

    PIXELFORMATDESCRIPTOR pfd_request;
    ZeroMemory(&pfd_request, sizeof(pfd_request));
    pfd_request.nSize = sizeof(pfd_request);
    pfd_request.nVersion = 1;
    pfd_request.dwFlags = flags;
    pfd_request.iPixelType = PFD_TYPE_RGBA;
    pfd_request.cColorBits = 32;
    pfd_request.cDepthBits = 24;
    pfd_request.iLayerType = PFD_MAIN_PLANE;

    auto pixelFormatIndex = ::ChoosePixelFormat(
        device_context,
        &pfd_request);

    if (pixelFormatIndex == 0) {
        error_message_ = "Failed to choose pixel format.";
        return false;
    }


    // Get choosen format
    //

    PIXELFORMATDESCRIPTOR pfd_response;
    ZeroMemory(&pfd_response, sizeof(pfd_response));

    auto describeResult = ::DescribePixelFormat(
        device_context,
        pixelFormatIndex,
        pfd_request.nSize,
        &pfd_response);

    if (describeResult == 0) {
        error_message_ = "Failed to get choosen pixel format.";
        return false;
    }


    // Compare formats
    //


    if (pfd_response.nSize < pfd_request.nSize) {
        error_message_ =
            "Choosen format structure size less then requested one.";

        return false;
    }

    if ((pfd_response.dwFlags & pfd_request.dwFlags) !=
        pfd_request.dwFlags)
    {
        error_message_ =
            "Choosen format flags does not contain requested ones.";

        return false;
    }

    if (pfd_response.iPixelType != pfd_request.iPixelType) {
        error_message_ =
            "Choosen pixel type does not match requested one.";

        return false;
    }

    if (pfd_response.cColorBits != pfd_request.cColorBits) {
        error_message_ =
            "Choosen color bits does not match requested ones.";

        return false;
    }

    if (pfd_response.cDepthBits != pfd_request.cDepthBits) {
        error_message_ =
            "Choosen depth bits does not match requested ones.";

        return false;
    }

    if (pfd_response.cStencilBits != pfd_request.cStencilBits) {
        error_message_ =
            "Choosen stencil bits does not match requested ones.";

        return false;
    }

    if (pfd_response.iLayerType != pfd_request.iLayerType) {
        error_message_ =
            "Choosen format layer type does not match requested one.";

        return false;
    }


    // Set format
    //

    auto setFormatResult = ::SetPixelFormat(
        device_context,
        pixelFormatIndex,
        &pfd_request);

    if (setFormatResult == FALSE) {
        error_message_ =
            "Failed to set pixel format.";

        return false;
    }

    return true;
}

bool Wrapper::initialize_ogl_context(
    HWND device_window)
{
    uninitialize_ogl_context();

    if (!preinitialize_ogl_context(
        device_window))
    {
        return false;
    }

    auto is_succeed = true;
    std::string error_message;
    Strings missing_symbols;
    HDC device_context = nullptr;
    HGLRC ogl_context = nullptr;

    if (is_succeed) {
        device_context = ::GetDC(
            device_window);

        if (!device_context) {
            is_succeed = false;
            error_message = "Failed to get device context.";
        }
    }

    if (is_succeed) {
        ogl_context = ::wglCreateContext(
            device_context);

        if (!ogl_context) {
            is_succeed = false;
            error_message = "Failed to create OpenGL context.";
        }
    }

    if (is_succeed) {
        auto result = ::wglMakeCurrent(
            device_context,
            ogl_context);

        if (result == FALSE) {
            is_succeed = false;
            error_message = "Failed to make OpenGL context current.";
        }
    }


    if (is_succeed) {
        //
        // Extensions
        //

        ogl_get_symbol(
            "glActiveTexture",
            glActiveTexture_,
            missing_symbols);

        ogl_get_symbol(
            "glAttachShader",
            glAttachShader_,
            missing_symbols);

        ogl_get_symbol(
            "glBindBuffer",
            glBindBuffer_,
            missing_symbols);

        ogl_get_symbol(
            "glBufferData",
            glBufferData_,
            missing_symbols);

        ogl_get_symbol(
            "glCompileShader",
            glCompileShader_,
            missing_symbols);

        ogl_get_symbol(
            "glCreateProgram",
            glCreateProgram_,
            missing_symbols);

        ogl_get_symbol(
            "glCreateShader",
            glCreateShader_,
            missing_symbols);

        ogl_get_symbol(
            "glDeleteBuffers",
            glDeleteBuffers_,
            missing_symbols);

        ogl_get_symbol(
            "glDeleteProgram",
            glDeleteProgram_,
            missing_symbols);

        ogl_get_symbol(
            "glDeleteShader",
            glDeleteShader_,
            missing_symbols);

        ogl_get_symbol(
            "glDetachShader",
            glDetachShader_,
            missing_symbols);

        ogl_get_symbol(
            "glDisableVertexAttribArray",
            glDisableVertexAttribArray_,
            missing_symbols);

        ogl_get_symbol(
            "glEnableVertexAttribArray",
            glEnableVertexAttribArray_,
            missing_symbols);

        ogl_get_symbol(
            "glGenBuffers",
            glGenBuffers_,
            missing_symbols);

        ogl_get_symbol(
            "glGetAttribLocation",
            glGetAttribLocation_,
            missing_symbols);

        ogl_get_symbol(
            "glGetProgramInfoLog",
            glGetProgramInfoLog_,
            missing_symbols);

        ogl_get_symbol(
            "glGetProgramiv",
            glGetProgramiv_,
            missing_symbols);

        ogl_get_symbol(
            "glGetShaderInfoLog",
            glGetShaderInfoLog_,
            missing_symbols);

        ogl_get_symbol(
            "glGetShaderiv",
            glGetShaderiv_,
            missing_symbols);

        ogl_get_symbol(
            "glGetUniformLocation",
            glGetUniformLocation_,
            missing_symbols);

        ogl_get_symbol(
            "glIsProgram",
            glIsProgram_,
            missing_symbols);

        ogl_get_symbol(
            "glIsShader",
            glIsShader_,
            missing_symbols);

        ogl_get_symbol(
            "glLinkProgram",
            glLinkProgram_,
            missing_symbols);

        ogl_get_symbol(
            "glShaderSource",
            glShaderSource_,
            missing_symbols);

        ogl_get_symbol(
            "glUniform1i",
            glUniform1i_,
            missing_symbols);

        ogl_get_symbol(
            "glUniformMatrix4fv",
            glUniformMatrix4fv_,
            missing_symbols);

        ogl_get_symbol(
            "glUseProgram",
            glUseProgram_,
            missing_symbols);

        ogl_get_symbol(
            "glVertexAttribPointer",
            glVertexAttribPointer_,
            missing_symbols);

        if (!missing_symbols.empty()) {
            is_succeed = false;

            error_message = ogl_build_error_message(
                missing_symbols);
        }
    }

    if (!is_succeed) {
        uninitialize_ogl_context();
    }

    return is_succeed;
}

void Wrapper::uninitialize_ogl()
{
    uninitialize_ogl_context();

    glIsShader_ = nullptr;
    glActiveTexture_ = nullptr;
    glAttachShader_ = nullptr;
    glBindBuffer_ = nullptr;
    glBufferData_ = nullptr;
    glCompileShader_ = nullptr;
    glCreateProgram_ = nullptr;
    glCreateShader_ = nullptr;
    glDeleteBuffers_ = nullptr;
    glDeleteProgram_ = nullptr;
    glDeleteShader_ = nullptr;
    glDetachShader_ = nullptr;
    glDisableVertexAttribArray_ = nullptr;
    glEnableVertexAttribArray_ = nullptr;
    glGenBuffers_ = nullptr;
    glGetAttribLocation_ = nullptr;
    glGetProgramInfoLog_ = nullptr;
    glGetProgramiv_ = nullptr;
    glGetShaderInfoLog_ = nullptr;
    glGetShaderiv_ = nullptr;
    glGetUniformLocation_ = nullptr;
    glIsProgram_ = nullptr;
    glLinkProgram_ = nullptr;
    glShaderSource_ = nullptr;
    glUniform1i_ = nullptr;
    glUniformMatrix4fv_ = nullptr;
    glUseProgram_ = nullptr;
    glVertexAttribPointer_ = nullptr;

    mode_ = Mode::none;
}

void Wrapper::uninitialize_ogl_context()
{
    auto device_context = ::wglGetCurrentDC();
    auto ogl_context = ::wglGetCurrentContext();

    if (!ogl_context || !device_context) {
        return;
    }

    static_cast<void>(::wglMakeCurrent(
        device_context,
        nullptr));

    static_cast<void>(::wglDeleteContext(
        ogl_context));
}


} // d3d9
} // ltjs
