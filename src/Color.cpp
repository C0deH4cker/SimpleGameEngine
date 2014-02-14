//
//  Color.cpp
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/7/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#include "Color.h"
#include <iostream>
#include "sge_depends.h"
#include "helpers.h"

using namespace sge;

// I think I parsed HTML with regex :O
// http://www.kyleschouviller.com/files/xnacolors/xnacolorss.html
const Color Color::AliceBlue{240.0f / 255.0f, 248.0f / 255.0f, 255.0f / 255.0f};
const Color Color::AntiqueWhite{250.0f / 255.0f, 235.0f / 255.0f, 215.0f / 255.0f};
const Color Color::Aqua{0.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f};
const Color Color::Aquamarine{127.0f / 255.0f, 255.0f / 255.0f, 212.0f / 255.0f};
const Color Color::Azure{240.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f};
const Color Color::Beige{245.0f / 255.0f, 245.0f / 255.0f, 220.0f / 255.0f};
const Color Color::Bisque{255.0f / 255.0f, 228.0f / 255.0f, 196.0f / 255.0f};
const Color Color::Black{0.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f};
const Color Color::BlanchedAlmond{255.0f / 255.0f, 235.0f / 255.0f, 205.0f / 255.0f};
const Color Color::Blue{0.0f / 255.0f, 0.0f / 255.0f, 255.0f / 255.0f};
const Color Color::BlueViolet{138.0f / 255.0f, 43.0f / 255.0f, 226.0f / 255.0f};
const Color Color::Brown{165.0f / 255.0f, 42.0f / 255.0f, 42.0f / 255.0f};
const Color Color::BurlyWood{222.0f / 255.0f, 184.0f / 255.0f, 135.0f / 255.0f};
const Color Color::CadetBlue{95.0f / 255.0f, 158.0f / 255.0f, 160.0f / 255.0f};
const Color Color::Chartreuse{127.0f / 255.0f, 255.0f / 255.0f, 0.0f / 255.0f};
const Color Color::Chocolate{210.0f / 255.0f, 105.0f / 255.0f, 30.0f / 255.0f};
const Color Color::Coral{255.0f / 255.0f, 127.0f / 255.0f, 80.0f / 255.0f};
const Color Color::CornflowerBlue{100.0f / 255.0f, 149.0f / 255.0f, 237.0f / 255.0f};
const Color Color::Cornsilk{255.0f / 255.0f, 248.0f / 255.0f, 220.0f / 255.0f};
const Color Color::Crimson{220.0f / 255.0f, 20.0f / 255.0f, 60.0f / 255.0f};
const Color Color::Cyan{0.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f};
const Color Color::DarkBlue{0.0f / 255.0f, 0.0f / 255.0f, 139.0f / 255.0f};
const Color Color::DarkCyan{0.0f / 255.0f, 139.0f / 255.0f, 139.0f / 255.0f};
const Color Color::DarkGoldenrod{184.0f / 255.0f, 134.0f / 255.0f, 11.0f / 255.0f};
const Color Color::DarkGray{169.0f / 255.0f, 169.0f / 255.0f, 169.0f / 255.0f};
const Color Color::DarkGreen{0.0f / 255.0f, 100.0f / 255.0f, 0.0f / 255.0f};
const Color Color::DarkKhaki{189.0f / 255.0f, 183.0f / 255.0f, 107.0f / 255.0f};
const Color Color::DarkMagenta{139.0f / 255.0f, 0.0f / 255.0f, 139.0f / 255.0f};
const Color Color::DarkOliveGreen{85.0f / 255.0f, 107.0f / 255.0f, 47.0f / 255.0f};
const Color Color::DarkOrange{255.0f / 255.0f, 140.0f / 255.0f, 0.0f / 255.0f};
const Color Color::DarkOrchid{153.0f / 255.0f, 50.0f / 255.0f, 204.0f / 255.0f};
const Color Color::DarkRed{139.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f};
const Color Color::DarkSalmon{233.0f / 255.0f, 150.0f / 255.0f, 122.0f / 255.0f};
const Color Color::DarkSeaGreen{143.0f / 255.0f, 188.0f / 255.0f, 139.0f / 255.0f};
const Color Color::DarkSlateBlue{72.0f / 255.0f, 61.0f / 255.0f, 139.0f / 255.0f};
const Color Color::DarkSlateGray{47.0f / 255.0f, 79.0f / 255.0f, 79.0f / 255.0f};
const Color Color::DarkTurquoise{0.0f / 255.0f, 206.0f / 255.0f, 209.0f / 255.0f};
const Color Color::DarkViolet{148.0f / 255.0f, 0.0f / 255.0f, 211.0f / 255.0f};
const Color Color::DeepPink{255.0f / 255.0f, 20.0f / 255.0f, 147.0f / 255.0f};
const Color Color::DeepSkyBlue{0.0f / 255.0f, 191.0f / 255.0f, 255.0f / 255.0f};
const Color Color::DimGray{105.0f / 255.0f, 105.0f / 255.0f, 105.0f / 255.0f};
const Color Color::DodgerBlue{30.0f / 255.0f, 144.0f / 255.0f, 255.0f / 255.0f};
const Color Color::Firebrick{178.0f / 255.0f, 34.0f / 255.0f, 34.0f / 255.0f};
const Color Color::FloralWhite{255.0f / 255.0f, 250.0f / 255.0f, 240.0f / 255.0f};
const Color Color::ForestGreen{34.0f / 255.0f, 139.0f / 255.0f, 34.0f / 255.0f};
const Color Color::Fuchsia{255.0f / 255.0f, 0.0f / 255.0f, 255.0f / 255.0f};
const Color Color::Gainsboro{220.0f / 255.0f, 220.0f / 255.0f, 220.0f / 255.0f};
const Color Color::GhostWhite{248.0f / 255.0f, 248.0f / 255.0f, 255.0f / 255.0f};
const Color Color::Gold{255.0f / 255.0f, 215.0f / 255.0f, 0.0f / 255.0f};
const Color Color::Goldenrod{218.0f / 255.0f, 165.0f / 255.0f, 32.0f / 255.0f};
const Color Color::Gray{128.0f / 255.0f, 128.0f / 255.0f, 128.0f / 255.0f};
const Color Color::Green{0.0f / 255.0f, 128.0f / 255.0f, 0.0f / 255.0f};
const Color Color::GreenYellow{173.0f / 255.0f, 255.0f / 255.0f, 47.0f / 255.0f};
const Color Color::Honeydew{240.0f / 255.0f, 255.0f / 255.0f, 240.0f / 255.0f};
const Color Color::HotPink{255.0f / 255.0f, 105.0f / 255.0f, 180.0f / 255.0f};
const Color Color::IndianRed{205.0f / 255.0f, 92.0f / 255.0f, 92.0f / 255.0f};
const Color Color::Indigo{75.0f / 255.0f, 0.0f / 255.0f, 130.0f / 255.0f};
const Color Color::Ivory{255.0f / 255.0f, 255.0f / 255.0f, 240.0f / 255.0f};
const Color Color::Khaki{240.0f / 255.0f, 230.0f / 255.0f, 140.0f / 255.0f};
const Color Color::Lavender{230.0f / 255.0f, 230.0f / 255.0f, 250.0f / 255.0f};
const Color Color::LavenderBlush{255.0f / 255.0f, 240.0f / 255.0f, 245.0f / 255.0f};
const Color Color::LawnGreen{124.0f / 255.0f, 252.0f / 255.0f, 0.0f / 255.0f};
const Color Color::LemonChiffon{255.0f / 255.0f, 250.0f / 255.0f, 205.0f / 255.0f};
const Color Color::LightBlue{173.0f / 255.0f, 216.0f / 255.0f, 230.0f / 255.0f};
const Color Color::LightCoral{240.0f / 255.0f, 128.0f / 255.0f, 128.0f / 255.0f};
const Color Color::LightCyan{224.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f};
const Color Color::LightGoldenrodYellow{250.0f / 255.0f, 250.0f / 255.0f, 210.0f / 255.0f};
const Color Color::LightGray{211.0f / 255.0f, 211.0f / 255.0f, 211.0f / 255.0f};
const Color Color::LightGreen{144.0f / 255.0f, 238.0f / 255.0f, 144.0f / 255.0f};
const Color Color::LightPink{255.0f / 255.0f, 182.0f / 255.0f, 193.0f / 255.0f};
const Color Color::LightSalmon{255.0f / 255.0f, 160.0f / 255.0f, 122.0f / 255.0f};
const Color Color::LightSeaGreen{32.0f / 255.0f, 178.0f / 255.0f, 170.0f / 255.0f};
const Color Color::LightSkyBlue{135.0f / 255.0f, 206.0f / 255.0f, 250.0f / 255.0f};
const Color Color::LightSlateGray{119.0f / 255.0f, 136.0f / 255.0f, 153.0f / 255.0f};
const Color Color::LightSteelBlue{176.0f / 255.0f, 196.0f / 255.0f, 222.0f / 255.0f};
const Color Color::LightYellow{255.0f / 255.0f, 255.0f / 255.0f, 224.0f / 255.0f};
const Color Color::Lime{0.0f / 255.0f, 255.0f / 255.0f, 0.0f / 255.0f};
const Color Color::LimeGreen{50.0f / 255.0f, 205.0f / 255.0f, 50.0f / 255.0f};
const Color Color::Linen{250.0f / 255.0f, 240.0f / 255.0f, 230.0f / 255.0f};
const Color Color::Magenta{255.0f / 255.0f, 0.0f / 255.0f, 255.0f / 255.0f};
const Color Color::Maroon{128.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f};
const Color Color::MediumAquamarine{102.0f / 255.0f, 205.0f / 255.0f, 170.0f / 255.0f};
const Color Color::MediumBlue{0.0f / 255.0f, 0.0f / 255.0f, 205.0f / 255.0f};
const Color Color::MediumOrchid{186.0f / 255.0f, 85.0f / 255.0f, 211.0f / 255.0f};
const Color Color::MediumPurple{147.0f / 255.0f, 112.0f / 255.0f, 219.0f / 255.0f};
const Color Color::MediumSeaGreen{60.0f / 255.0f, 179.0f / 255.0f, 113.0f / 255.0f};
const Color Color::MediumSlateBlue{123.0f / 255.0f, 104.0f / 255.0f, 238.0f / 255.0f};
const Color Color::MediumSpringGreen{0.0f / 255.0f, 250.0f / 255.0f, 154.0f / 255.0f};
const Color Color::MediumTurquoise{72.0f / 255.0f, 209.0f / 255.0f, 204.0f / 255.0f};
const Color Color::MediumVioletRed{199.0f / 255.0f, 21.0f / 255.0f, 133.0f / 255.0f};
const Color Color::MidnightBlue{25.0f / 255.0f, 25.0f / 255.0f, 112.0f / 255.0f};
const Color Color::MintCream{245.0f / 255.0f, 255.0f / 255.0f, 250.0f / 255.0f};
const Color Color::MistyRose{255.0f / 255.0f, 228.0f / 255.0f, 225.0f / 255.0f};
const Color Color::Moccasin{255.0f / 255.0f, 228.0f / 255.0f, 181.0f / 255.0f};
const Color Color::NavajoWhite{255.0f / 255.0f, 222.0f / 255.0f, 173.0f / 255.0f};
const Color Color::Navy{0.0f / 255.0f, 0.0f / 255.0f, 128.0f / 255.0f};
const Color Color::OldLace{253.0f / 255.0f, 245.0f / 255.0f, 230.0f / 255.0f};
const Color Color::Olive{128.0f / 255.0f, 128.0f / 255.0f, 0.0f / 255.0f};
const Color Color::OliveDrab{107.0f / 255.0f, 142.0f / 255.0f, 35.0f / 255.0f};
const Color Color::Orange{255.0f / 255.0f, 165.0f / 255.0f, 0.0f / 255.0f};
const Color Color::OrangeRed{255.0f / 255.0f, 69.0f / 255.0f, 0.0f / 255.0f};
const Color Color::Orchid{218.0f / 255.0f, 112.0f / 255.0f, 214.0f / 255.0f};
const Color Color::PaleGoldenrod{238.0f / 255.0f, 232.0f / 255.0f, 170.0f / 255.0f};
const Color Color::PaleGreen{152.0f / 255.0f, 251.0f / 255.0f, 152.0f / 255.0f};
const Color Color::PaleTurquoise{175.0f / 255.0f, 238.0f / 255.0f, 238.0f / 255.0f};
const Color Color::PaleVioletRed{219.0f / 255.0f, 112.0f / 255.0f, 147.0f / 255.0f};
const Color Color::PapayaWhip{255.0f / 255.0f, 239.0f / 255.0f, 213.0f / 255.0f};
const Color Color::PeachPuff{255.0f / 255.0f, 218.0f / 255.0f, 185.0f / 255.0f};
const Color Color::Peru{205.0f / 255.0f, 133.0f / 255.0f, 63.0f / 255.0f};
const Color Color::Pink{255.0f / 255.0f, 192.0f / 255.0f, 203.0f / 255.0f};
const Color Color::Plum{221.0f / 255.0f, 160.0f / 255.0f, 221.0f / 255.0f};
const Color Color::PowderBlue{176.0f / 255.0f, 224.0f / 255.0f, 230.0f / 255.0f};
const Color Color::Purple{128.0f / 255.0f, 0.0f / 255.0f, 128.0f / 255.0f};
const Color Color::Red{255.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f};
const Color Color::RosyBrown{188.0f / 255.0f, 143.0f / 255.0f, 143.0f / 255.0f};
const Color Color::RoyalBlue{65.0f / 255.0f, 105.0f / 255.0f, 225.0f / 255.0f};
const Color Color::SaddleBrown{139.0f / 255.0f, 69.0f / 255.0f, 19.0f / 255.0f};
const Color Color::Salmon{250.0f / 255.0f, 128.0f / 255.0f, 114.0f / 255.0f};
const Color Color::SandyBrown{244.0f / 255.0f, 164.0f / 255.0f, 96.0f / 255.0f};
const Color Color::SeaGreen{46.0f / 255.0f, 139.0f / 255.0f, 87.0f / 255.0f};
const Color Color::SeaShell{255.0f / 255.0f, 245.0f / 255.0f, 238.0f / 255.0f};
const Color Color::Sienna{160.0f / 255.0f, 82.0f / 255.0f, 45.0f / 255.0f};
const Color Color::Silver{192.0f / 255.0f, 192.0f / 255.0f, 192.0f / 255.0f};
const Color Color::SkyBlue{135.0f / 255.0f, 206.0f / 255.0f, 235.0f / 255.0f};
const Color Color::SlateBlue{106.0f / 255.0f, 90.0f / 255.0f, 205.0f / 255.0f};
const Color Color::SlateGray{112.0f / 255.0f, 128.0f / 255.0f, 144.0f / 255.0f};
const Color Color::Snow{255.0f / 255.0f, 250.0f / 255.0f, 250.0f / 255.0f};
const Color Color::SpringGreen{0.0f / 255.0f, 255.0f / 255.0f, 127.0f / 255.0f};
const Color Color::SteelBlue{70.0f / 255.0f, 130.0f / 255.0f, 180.0f / 255.0f};
const Color Color::Tan{210.0f / 255.0f, 180.0f / 255.0f, 140.0f / 255.0f};
const Color Color::Teal{0.0f / 255.0f, 128.0f / 255.0f, 128.0f / 255.0f};
const Color Color::Thistle{216.0f / 255.0f, 191.0f / 255.0f, 216.0f / 255.0f};
const Color Color::Tomato{255.0f / 255.0f, 99.0f / 255.0f, 71.0f / 255.0f};
const Color Color::TransparentBlack{0.0f / 255.0f, 0.0f / 255.0f, 0.0f / 255.0f};
const Color Color::TransparentWhite{255.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f};
const Color Color::Turquoise{64.0f / 255.0f, 224.0f / 255.0f, 208.0f / 255.0f};
const Color Color::Violet{238.0f / 255.0f, 130.0f / 255.0f, 238.0f / 255.0f};
const Color Color::Wheat{245.0f / 255.0f, 222.0f / 255.0f, 179.0f / 255.0f};
const Color Color::White{255.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f};
const Color Color::WhiteSmoke{245.0f / 255.0f, 245.0f / 255.0f, 245.0f / 255.0f};
const Color Color::Yellow{255.0f / 255.0f, 255.0f / 255.0f, 0.0f / 255.0f};
const Color Color::YellowGreen{154.0f / 255.0f, 205.0f / 255.0f, 50.0f / 255.0f};



Color::Color()
: Color(0.0f, 0.0f, 0.0f, 1.0f) {}

Color::Color(const Color& orig)
: Color(orig.r, orig.g, orig.b, orig.a) {}

Color::Color(float r, float g, float b, float a)
: r(CLAMP(r, 0.0f, 1.0f)),
  g(CLAMP(g, 0.0f, 1.0f)),
  b(CLAMP(b, 0.0f, 1.0f)),
  a(CLAMP(a, 0.0f, 1.0f)) {}

Color::Color(unsigned rgb, float a)
: Color(((rgb >> 16) & 255) / 255.0f,
		((rgb >>  8) & 255) / 255.0f,
        ((rgb >>  4) & 255) / 255.0f,
		a) {}

Color& Color::operator=(const Color& color) {
	r = color.r;
	g = color.g;
	b = color.b;
	a = color.a;
	return *this;
}

void Color::apply() const {
	glColor4f(r, g, b, a);
}

