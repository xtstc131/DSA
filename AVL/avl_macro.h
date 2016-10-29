#pragma once
#define Balance(x) (stature((x).lc) == stature((x),rc))
#define BalFac(x) (stature((x).lc) - stature((x).rc))
#define AvlBalaanced(x) ( (-2 < BalFac(x) ) && ( BalFac(x) < 2 ))