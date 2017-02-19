//
//  main.cpp
//  Playground
//
//  Created by Reyn-Mac on 2017/1/25.
//  Copyright © 2017年 Reyn-Mac. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include "Chromatics/Chromatics.hpp"
#include "StringUtils.hpp"
using namespace Chromatic;
using namespace std;

void RGB_TestCase() {
    cout << "<# RGB TestCase Start" << endl;
    
    cout << "=> RGB original data:" << endl;
    RGB case0 = RGB(REBECCAPURPLE);
    case0.dump();
    
    cout << endl << "=> single operator:" << endl;
    (case0+1).dump();
    (case0-1).dump();
    (case0*2).dump();
    (case0/2).dump();
    (case0%15.f).dump();
    cout << endl << "=> mixed  operator:" << endl;
    case0.clear(166);
    (case0+RGB(1,1,1)).dump();
    (case0-RGB(1,1,1)).dump();
    (case0*RGB(2,2,2)).dump();
    (case0/RGB(2,2,2)).dump();
    (case0%RGB(15,15,15)).dump();
    
    cout << endl << "=> use scale:" << endl;
    (case0.scale(10.8).dump());
    
    cout << endl << "=> use divide:" << endl;
    (case0.divide(2).dump());

    cout << endl << "=> from hex string(do check):" << endl;
    case0.fromHEX("80aF*U", true).dump();
    
    cout << endl << "=> from hex string(do not check):" << endl;
    case0.fromHEX("80aF*U", false).dump();
    
    cout << endl << "=> to hex string:" << endl;
    cout << case0.toHEX() << endl;
    
    cout << endl << "=> from/to RGBA:" << endl;
    case0.fromRGBA(case0.toRGBA().dump()).dump();
    
    cout << endl << "=> clear with:" << endl;
    case0.clear(255).dump();
    
    cout << endl << "=> RED + LIME = YELLOW : " << endl;
    (RGB(RED) + RGB(LIME)).dump();
    RGB(YELLOW).dump();
    
    cout << endl << "=> convertor: " << endl;
    RGB rgb = RGB().fromHEX(ANTIQUEWHITE).dump();
    rgb.toRGBA().dump();
    rgb.toCMYK().dump();
    rgb.toHSL().dump();
    
    cout << "!!! RGB TestCase End #>" << endl << endl;
}


void RGBA_TestCase() {
    cout << "<# RGBA TestCase Start" << endl;
    
    RGBA case0 = RGBA(INDIGO);
    
    cout << "=> RGBA original data:" << endl;
    case0.dump();
    
    cout << endl << "=> single operator:" << endl;
    (case0+1).dump();
    (case0-1).dump();
    (case0*2).dump();
    (case0/2).dump();
    (case0%15.f).dump();
    cout << endl << "=> mixed  operator:" << endl;
    case0.clear(166);
    (case0+RGBA(1,1,1,1)).dump();
    (case0-RGBA(1,1,1,1)).dump();
    (case0*RGBA(2,2,2,2)).dump();
    (case0/RGBA(2,2,2,2)).dump();
    (case0%RGBA(15,15,15,15)).dump();
    
    cout << endl << "=> use scale:" << endl;
    (case0.scale(10.8).dump());
    
    cout << endl << "=> use divide:" << endl;
    (case0.divide(2).dump());
    
    cout << endl << "=> from hex string (do check):" << endl;
    case0.fromHEX("80aF*UE", true).dump();
    
    cout << endl << "=> from hex string (do not check):" << endl;
    case0.fromHEX("80aF*UE", false).dump();
    
    cout << endl << "=> to hex string:" << endl;
    cout << case0.toHEX() << endl;
    
    cout << endl << "=> from/to RGB:" << endl;
    case0.fromRGB(case0.toRGB().dump()).dump();
    
    cout << endl << "=> clear with:" << endl;
    case0.clear(255).dump();
    
    cout << endl << "=> convertor: " << endl;
    RGBA rgba = RGBA().fromHEX(ANTIQUEWHITE).dump();
    rgba.toRGB().dump();
    rgba.toCMYK().dump();
    rgba.toHSL().dump();
    
    cout << "!!! RGBA TestCase End #>" << endl << endl;
}

void CMYK_TestCase() {
    cout << "<# CMYK TestCase Start " << endl;
    
    CMYK cmyk = CMYK().fromHEX(ANTIQUEWHITE).dump();
    cmyk.toRGB().dump();
    cmyk.toHSL().dump();
    cmyk.toRGBA().dump();
    
    cout << "!!! CMYK TestCase END #>" << endl << endl;
}

void HSL_TestCase() {
    cout << "<# HSL TestCase Start " << endl;
    
    HSL hsl = HSL().fromHEX(ANTIQUEWHITE).dump();
    hsl.toRGB().dump();
    hsl.toCMYK().dump();
    hsl.toRGBA().dump();
    
    cout << "!!! HSL TestCase Start #>" << endl << endl;
}

void HSV_TestCase() {
    cout << "<# HSV TestCase Start" << endl;
    HSV hsv = HSV().fromHEX(ANTIQUEWHITE).dump();
    hsv.toRGB().dump();
    hsv.toCMYK().dump();
    hsv.toRGBA().dump();
    cout << "!!! HSV TestCase End #>" << endl << endl;
}


void RGB_Blend_TestCase() {
    cout << "<# RGB Blend TestCase Start" << endl;
    
    bool bBlendRedLime = RGB(RED).blend(LIME) == YELLOW;
    cout << "Red blend Lime = Yellow ? ";
    bBlendRedLime ? cout << "True" : cout << "False";
    cout << endl;
    
    bBlendRedLime = RGB(RED).blend(LIME) + RGB(YELLOW).opposite() == WHITE;
    cout << "Red blend Green = Yellow ? ";
    bBlendRedLime ? cout << "True" : cout << "False";
    cout << endl;
    
    cout << "!!! RGB Blend TestCase End #>" << endl << endl;
}

void RGBA_Blend_TestCase() {
    cout << "<# RGBA Blend TestCase Start" << endl;
    
    RGBA c1 = RGBA().fromAlphaF(235, 152, 80, 0.6f).dump();
    RGBA c2 = RGBA().fromAlphaF(234, 97, 124, 0.8f).dump();
    c1.blend(c2).dump();
    
    cout << "RGBA Blend TestCase End #>" << endl << endl;
}

void ColorRandom_TestCase() {
    cout << "<# Color Random TestCase Start" << endl;
    
    RGB  c1 = RGB().random().dump();
    randomColor(c1).dump();
    RGBA c2 = RGBA().random().dump();
    randomColor(c2).dump();
    CMYK c3 = CMYK().random().dump();
    randomColor(c3).dump();
    HSL  c4 = HSL().random().dump();
    randomColor(c4).dump();
    HSV  c5 = HSV().random().dump();
    randomColor(c5).dump();
    
    cout << "!!! Color Random TestCase End #>" << endl << endl;
}

void CompareColor_TestCase() {
    cout << "<# Compare Color With Mode Start" << endl;
    
    RGB  c1 = RGB(LIMEGREEN).dump();
    RGBA c2 = RGBA(LIMEGREEN).alpha(88).dump();
    CMYK c3 = CMYK(LIMEGREEN).dump();
    HSL  c4 = HSL(LIMEGREEN).dump();
    HSV  c5 = HSV(LIMEGREEN).dump();
    cout << "[Color Value] LIMEGREEN: HEX(#32CD32)" << endl;
    cout << "[Color Mode ] c1: RGB, c2: RGBA, c3: CMYK, c4: HSL, c5: HSV " << endl;
    cout << "[CampareMode] loose :" << endl;
    cout << "c1 == c2 ? " << (equals(c1, c2) ? "True" : "False") << endl;
    cout << "c1 == c3 ? " << (equals(c1, c3) ? "True" : "False") << endl;
    cout << "c1 == c4 ? " << (equals(c1, c4) ? "True" : "False") << endl;
    cout << "c1 == c5 ? " << (equals(c1, c5) ? "True" : "False") << endl;
    cout << "c2 == c3 ? " << (equals(c2, c3) ? "True" : "False") << endl;
    cout << "c2 == c4 ? " << (equals(c2, c4) ? "True" : "False") << endl;
    cout << "c2 == c5 ? " << (equals(c2, c5) ? "True" : "False") << endl;
    cout << "c3 == c4 ? " << (equals(c3, c4) ? "True" : "False") << endl;
    cout << "c3 == c5 ? " << (equals(c3, c5) ? "True" : "False") << endl;
    cout << "c4 == c5 ? " << (equals(c4, c5) ? "True" : "False") << endl;
    cout << "[Color Value] LIMEGREEN: HEX(#32CD32)" << endl;
    cout << "[Color Mode ] c1: RGB, c2: RGBA, c3: CMYK, c4: HSL, c5: HSV " << endl;
    cout << "[CampareMode] strict :" << endl;
    cout << "c1 == c2 ? " << (sequals(c1, c2) ? "True" : "False") << endl;
    cout << "c1 == c3 ? " << (sequals(c1, c3) ? "True" : "False") << endl;
    cout << "c1 == c4 ? " << (sequals(c1, c4) ? "True" : "False") << endl;
    cout << "c1 == c5 ? " << (sequals(c1, c5) ? "True" : "False") << endl;
    cout << "c2 == c3 ? " << (sequals(c2, c3) ? "True" : "False") << endl;
    cout << "c2 == c4 ? " << (sequals(c2, c4) ? "True" : "False") << endl;
    cout << "c2 == c5 ? " << (sequals(c2, c5) ? "True" : "False") << endl;
    cout << "c3 == c4 ? " << (sequals(c3, c4) ? "True" : "False") << endl;
    cout << "c3 == c5 ? " << (sequals(c3, c5) ? "True" : "False") << endl;
    cout << "c4 == c5 ? " << (sequals(c4, c5) ? "True" : "False") << endl;
    
    cout << "!!! Compare Color With Mode End #>" << endl << endl;
}

int main() {
    RGB_TestCase();
    RGBA_TestCase();
    CMYK_TestCase();
    HSL_TestCase();
    HSV_TestCase();
    RGB_Blend_TestCase();
    RGBA_Blend_TestCase();
    ColorRandom_TestCase();
    CompareColor_TestCase();
}

