////////////////////////////////////////////////////////////////////////////
//
// Author:
//   Joakim Eriksson
//
////////////////////////////////////////////////////////////////////////////

#pragma once

/***************************** D E F I N E S *******************************/
/****************************** M A C R O S ********************************/
/***************************** C L A S S E S *******************************/

////////////////////////////////////////////////////////////////////////////
//

#ifndef WIN32
#include "shaders/GUIShader.h"
#endif
#include "kodi/AddonBase.h"

typedef struct  TRenderVertex
{
  CVector pos;
  CRGBA col;
} TRenderVertex;

////////////////////////////////////////////////////////////////////////////
//
class CPaddel
{
public:
  CVector m_Pos;
  CVector m_Size;
  CRGBA m_Col;

  CPaddel()
  {
    m_Pos.Zero();
    m_Size.Set(1.0f, 20.0f, 0.0f);
    m_Col.Set(1.0f, 1.0f, 1.0f, 1.0f);
  }
};

////////////////////////////////////////////////////////////////////////////
//
class CBall
{
public:
  CVector m_Pos;
  CVector m_Vel;
  CVector m_Size;
  CRGBA m_Col;

  CBall()
  {
    m_Pos.Set(300,300,0.0);
    m_Vel.Zero();
    m_Size.Set(2.0f, 2.0f, 2.0f);
    m_Col.Set(1.0f, 1.0f, 1.0f, 1.0f);
  }
};

////////////////////////////////////////////////////////////////////////////
//
class ATTRIBUTE_HIDDEN CPingPong
{
public:
  CPingPong();
  ~CPingPong();
  bool RestoreDevice(CRenderD3D* render);
  void InvalidateDevice(CRenderD3D* render);
  void Update(f32 dt);
  bool Draw(CRenderD3D* render);

  CPaddel m_Paddle[2];
  CBall m_Ball;
  int topy;
  int bottomy;
  int m_Width = 0;
  int m_Height = 0;
protected:
  TRenderVertex* AddQuad(TRenderVertex* vert, const CVector& pos, const CVector& size, const CRGBA& col);

#ifndef WIN32
  CGUIShader* m_shader;
  GLuint m_vertexVBO;
  GLuint m_indexVBO;
#endif
};
