//
// Sprite--�K�Ϲs��
//
//		Copyright (c) 2000 Chihiro.SAKAMOTO (HyperWorks)
//
#include "StdAfx.h"
#include "DibSection.h"
#include "Sprite.h"

// ø�s�K�Ϲs��
//
void CSprite::Draw(CDibSection &image)
{
	image.Mix(*dib, draw_pos, size, src_pos);
}

// ø�s�K�Ϲs��(��������)
//
void CSprite::Draw(CDibSection &image, const CRect &rect)
{
	CRect r(draw_pos, size);
	r &= rect;
	if (!r.IsRectEmpty()) {
		CPoint	src = src_pos;
		CPoint	dest = draw_pos;
		if (dest.x < r.left) {
			src.x += r.left - dest.x;
			dest.x = r.left;
		}
		if (dest.y < r.top) {
			src.y += r.top - dest.y;
			dest.y = r.top;
		}
		image.Mix(*dib, dest, r.Size(), src);
	}
}
