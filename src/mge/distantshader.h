#pragma once

enum RenderPassID {
    PASS_SETUP = 0,
    PASS_RENDERGRASSINST,
    PASS_RENDERSHADOW,
    PASS_RENDERSHADOWFFE,
    PASS_RENDERLAND,
    PASS_RENDERLANDREFL,
    PASS_RENDERSTATICSEXTERIOR,
    PASS_RENDERSTATICSINTERIOR,
    PASS_RENDERSKY,
    PASS_RENDERWATER,
    PASS_RENDERUNDERWATER,
    PASS_RENDERCAUSTICS,
    PASS_BLENDMGE,
    PASS_DEBUGSHADOW,
    PASS_PLAYERWAVE,
    PASS_WAVESTEP,
    PASS_WORKAROUND
};

enum RenderShadowMapID {
    PASS_CLEARSHADOWMAP = 0,
    PASS_SHADOWSTENCIL,
    PASS_RENDERSHADOWMAP,
    PASS_SOFTENSHADOWMAP
};

enum RenderDepthID {
    PASS_CLEARDEPTH = 0,
    PASS_RENDERMWDEPTH,
    PASS_RENDERLANDDEPTH,
    PASS_RENDERSTATICSDEPTH,
    PASS_RENDERGRASSDEPTHINST
};

static const int SIZEOFSTATICVERT = 20;
static const int SIZEOFLANDVERT = 16;
