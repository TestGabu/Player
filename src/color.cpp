/////////////////////////////////////////////////////////////////////////////
// This file is part of EasyRPG Player.
// 
// EasyRPG Player is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// EasyRPG Player is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with EasyRPG Player. If not, see <http://www.gnu.org/licenses/>.
/////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "color.h"

////////////////////////////////////////////////////////////
/// Constructor
////////////////////////////////////////////////////////////
Color::Color() {
	red = 0;
	green = 0;
	blue = 0;
	alpha = 255;
}
Color::Color(int ired, int igreen, int iblue, int ialpha) {
	red = ired;
	green = igreen;
	blue = iblue;
	alpha = ialpha;
}
Color::Color(Uint32 color, SDL_PixelFormat* format) {
	Uint8 r, g, b, a;
	SDL_GetRGBA(color, format, &r, &g, &b, &a);
	red = r;
	green = g;
	blue = b;
	alpha = a;
}

////////////////////////////////////////////////////////////
/// Destructor
////////////////////////////////////////////////////////////
Color::~Color() {
}

////////////////////////////////////////////////////////////
/// != operator
////////////////////////////////////////////////////////////
bool Color::operator!=(const Color &other) const {
	return red != other.red || green != other.green || blue != other.blue || alpha != other.alpha;
}

////////////////////////////////////////////////////////////
/// Set
////////////////////////////////////////////////////////////
void Color::Set(int nred, int ngreen, int nblue, int nalpha) {
	red = nred;
	green = ngreen;
	blue = nblue;
	alpha = nalpha;
}

////////////////////////////////////////////////////////////
/// Get Uint32
////////////////////////////////////////////////////////////
Uint32 Color::GetUint32(SDL_PixelFormat* format) {
	return SDL_MapRGBA(format, (Uint8)red, (Uint8)green, (Uint8)blue, (Uint8)alpha);
}

////////////////////////////////////////////////////////////
/// Get SDL_Color
////////////////////////////////////////////////////////////
SDL_Color Color::Get() {
	SDL_Color color = {red, green, blue, alpha};
	return color;
}
