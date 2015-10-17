#ifndef LTJS_D3D9_FVF_INCLUDED
#define LTJS_D3D9_FVF_INCLUDED


#include <d3d9.h>


namespace ltjs {
namespace d3d9 {


class Fvf {
public:
    DWORD value;


    Fvf() = delete;

    Fvf(
        DWORD fvf);

    bool has_xyz() const;

    bool has_xyzrhw() const;

    bool has_xyzb1() const;

    bool has_xyzb2() const;

    bool has_xyzb3() const;

    bool has_xyzb4() const;

    bool has_lastbyte_ubyte4() const;

    bool has_normal() const;

    bool has_diffuse() const;

    bool has_tex1() const;

    bool has_tex2() const;

    bool has_tex3() const;

    bool has_tex4() const;


    bool has_position() const;

    bool has_beta() const;

    bool has_tex() const;

    bool has_tex(
        int set_index) const;


    int get_beta_count() const;


    int get_tex_count() const;

    int get_tex_size(
        int set_index) const;
}; // Fvf


} // d3d9
} // ltjs


#endif // LTJS_D3D9_FVF_INCLUDED
