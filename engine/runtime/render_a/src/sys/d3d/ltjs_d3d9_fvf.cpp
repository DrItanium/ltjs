#include "precompile.h"
#include "ltjs_d3d9_fvf.h"
#include "ltjs_d3d9_exception.h"


namespace ltjs {
namespace d3d9 {


Fvf::Fvf(
    DWORD fvf) :
        value(fvf)
{
}

bool Fvf::has_xyz() const
{
    return (value & 0xF) == D3DFVF_XYZ;
}

bool Fvf::has_xyzrhw() const
{
    return (value & 0xF) == D3DFVF_XYZRHW;
}

bool Fvf::has_xyzb1() const
{
    return (value & 0xF) == D3DFVF_XYZB1;
}

bool Fvf::has_xyzb2() const
{
    return (value & 0xF) == D3DFVF_XYZB2;
}

bool Fvf::has_xyzb3() const
{
    return (value & 0xF) == D3DFVF_XYZB3;
}

bool Fvf::has_xyzb4() const
{
    return (value & 0xF) == D3DFVF_XYZB4;
}

bool Fvf::has_lastbyte_ubyte4() const
{
    return (value & D3DFVF_LASTBETA_UBYTE4) != 0;
}

bool Fvf::has_normal() const
{
    return (value & D3DFVF_NORMAL) != 0;
}

bool Fvf::has_diffuse() const
{
    return (value & D3DFVF_DIFFUSE) != 0;
}

bool Fvf::has_tex1() const
{
    return (value & 0xF00) == D3DFVF_TEX1;
}

bool Fvf::has_tex2() const
{
    return (value & 0xF00) == D3DFVF_TEX2;
}

bool Fvf::has_tex3() const
{
    return (value & 0xF00) == D3DFVF_TEX3;
}

bool Fvf::has_tex4() const
{
    return (value & 0xF00) == D3DFVF_TEX4;
}

bool Fvf::has_position() const
{
    return has_xyz() | has_xyzrhw() | has_beta();
}

bool Fvf::has_beta() const
{
    return
        has_xyzb1() |
        has_xyzb2() |
        has_xyzb3() |
        has_xyzb4();
}

bool Fvf::has_tex() const
{
    return
        has_tex1() |
        has_tex2() |
        has_tex3() |
        has_tex4();
}

bool Fvf::has_tex(
    int set_index) const
{
    switch (set_index) {
    case 0:
        return has_tex1();

    case 1:
        return has_tex2();

    case 2:
        return has_tex3();

    case 3:
        return has_tex4();

    default:
        return false;
    }
}

int Fvf::get_beta_count() const
{
    switch (value & 0xE) {
    case D3DFVF_XYZB1:
        return 1;

    case D3DFVF_XYZB2:
        return 2;

    case D3DFVF_XYZB3:
        return 3;

    case D3DFVF_XYZB4:
        return 4;

    default:
        return 0;
    }
}

int Fvf::get_tex_count() const
{
    switch (value & 0xF00) {
    case D3DFVF_TEX1:
        return 1;

    case D3DFVF_TEX2:
        return 2;

    case D3DFVF_TEX3:
        return 3;

    case D3DFVF_TEX4:
        return 4;

    default:
        return 0;
    }
}

int Fvf::get_tex_size(
    int set_index) const
{
    if (!has_tex(set_index)) {
        return 0;
    }

    auto encoded_size = (value >> (16 + (2 * set_index))) & 0x3;

    switch (encoded_size) {
    case 0:
        return 2;

    case 1:
        return 3;

    case 3:
        return 1;

    default:
        return 0;
    }
}


} // d3d9
} // ltjs
