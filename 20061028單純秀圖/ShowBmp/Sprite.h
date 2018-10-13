//
// Sprite--�K�Ϲs��
//
//		Copyright (c) 2000 Chihiro.SAKAMOTO (HyperWorks)
//
#ifndef	__sprite_h__
#define	__sprite_h__

class CDibSection;
class CSprite {
  public:
	CSprite();
	CSprite(CDibSection *dib, CPoint pos, CSize _size, int d=0);
	CSprite(CDibSection *dib, CPoint pos, CPoint src, CSize _size, int d=0);
	virtual ~CSprite();

	void Set(CDibSection *dib, CPoint pos, CSize _size, int d=0);
	void Set(CDibSection *dib, CPoint pos, CPoint src, CSize _size, int d=0);
	void Draw(CDibSection &image);
	void Draw(CDibSection &image, const CRect &rect);
	void GetRect(CRect *r) const;
	void SetDrawPos(int x, int y);
	void SetDrawPos(CPoint point);
	CPoint GetDrawPos() const;
	void SetSrcPos(int x, int y);
	int GetDepth() const;
	void SetDepth(int d);
	BOOL PtIn(POINT pt);

  protected:
	CPoint	draw_pos;
	CPoint	src_pos;
	CSize	size;
	CDibSection *dib;
	int		depth;
} ;

// �غc��
//
inline CSprite::CSprite()
{
	draw_pos.x = 0;
	draw_pos.y = 0;
	src_pos.x = 0;
	src_pos.y = 0;
	size.cx = 0;
	size.cy = 0;
	dib = 0;
	depth = 0;
}

inline CSprite::CSprite(CDibSection *image, CPoint pos, CSize _size, int d)
{
	draw_pos = pos;
	src_pos.x = 0;
	src_pos.y = 0;
	size = _size;
	dib = image;
	depth = d;
}

inline CSprite::CSprite(CDibSection *image, CPoint pos, CPoint src, CSize _size, int d)
{
	draw_pos = pos;
	src_pos = src;
	size = _size;
	dib = image;
	depth = d;
}

// �Ѻc��
//
inline CSprite::~CSprite()
{
}

// �N�ѼƳ]�w�b�غc�n������W
//
inline void CSprite::Set(CDibSection *_dib, CPoint pos, CSize _size, int d)
{
	draw_pos = pos;
	size = _size;
	dib = _dib;
	depth = d;
}

inline void CSprite::Set(CDibSection *_dib, CPoint pos, CPoint src, CSize _size, int d)
{
	draw_pos = pos;
	src_pos = src;
	size = _size;
	dib = _dib;
	depth = d;
}

// �]�w�v���ƻs�����y��
//
inline void CSprite::SetSrcPos(int x, int y)
{
	src_pos.x = x;
	src_pos.y = y;
}

// �]�w�v���ƻs�ت�(�yø)���y��
//
inline void CSprite::SetDrawPos(int x, int y)
{
	draw_pos.x = x;
	draw_pos.y = y;
}

inline void CSprite::SetDrawPos(CPoint point)
{
	draw_pos = point;
}

// ���o�v���ƻs�ت��]�yø�^���y��
//
inline CPoint CSprite::GetDrawPos() const
{
	return draw_pos;
}

// ���o�v���`��(ø�s����)
//
inline int CSprite::GetDepth() const
{
	return depth;
}

// �]�w�v���`��(ø�s����)
//
inline void CSprite::SetDepth(int d)
{
	depth = d;
}

// ���o�v������ܽd��
//
inline void CSprite::GetRect(CRect *r) const
{
	r->left = draw_pos.x;
	r->top = draw_pos.y;
	r->right = draw_pos.x + size.cx;
	r->bottom = draw_pos.y + size.cy;
}

// ���w�y�ЬO�_�b�v����ܪ��d��?
//
inline BOOL CSprite::PtIn(POINT pt)
{
	return CRect(draw_pos, size).PtInRect(pt);
}

#endif
