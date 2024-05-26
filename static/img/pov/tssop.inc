#include "colors.inc"    // The include files contain
#include "stones.inc"    // pre-defined scene elements
#include "textures.inc"    // pre-defined scene elements
#include "shapes.inc"
#include "glass.inc"
#include "metals.inc"
#include "woods.inc"

#include "Round_Box_Y.inc"

background { colour rgbt <0.0, 0.0, 0.0, 1.0> }

light_source { <10, 15, -10> color White}

/*
sphere {
  <0, 2, 0>, 2
  texture {
    pigment { color Yellow }
  }
}
*/

// plane {
//   <0 1 0>, 0
//   texture {
//     pigment { color <0,0,0> transmit 0.0 }
//     // pigment { Yellow }
//   }
// }

#declare pinshape_clamp = function(v,lo,hi) { max(lo, min(hi, v)) }
#declare pinshape_smoothstep = function(x,n) { pow(x,n)/(pow(x,n)+pow(1.0-x,n)) };
#declare pinshape_lx = function(x) { pinshape_clamp(0.6 + 1.6*(x - 0.5), 0.0, 1.0) };
#declare pinshape_b = function(x) { pinshape_smoothstep(pinshape_lx(x), 3.0) };
#declare pinshape_hc = function(x,c) { c / 2.0 + 0.08*pow(1.0-1.5*abs(pinshape_lx(x)-0.5),3.0) };
#declare pinshape_ly = function(x,c) { (1.0 - 2.0 * pinshape_hc(x,c)) * (1.0 - pinshape_b(x)) + pinshape_hc(x,c) };
#declare pinshape_dist2d = function (x,y,c) { abs(y - pinshape_ly(x,c)) - pinshape_hc(x,c) };

// #declare pinshape = function(x,y,z,c,w) { min(abs(z) - w,  pinshape_dist2d(x,y,c)) };
#declare pinshape = function(x,y,z,c,w) { max(abs(z)-w/2, pinshape_dist2d(x,y,c)) };

#macro microchipPin(pos, rot, L, H, c, w)
  object{
    isosurface {
      function { pinshape(x,y,z,c/H,w) }
      contained_by { box { <0,0,-w/2>, <1,1,w/2> } }
      max_gradient 4.1
    }
    pigment { color rgb<0.8,0.8,0.8> }
    finish { phong 1 reflection 0.3 }
    scale <L,H,1>
    rotate <0,rot,0>
    translate pos
  }
#end

// microchip_pin(< 0.5,0,0>, 0  , 1.0, 1.0, 0.1, 0.2)
// microchip_pin(<-0.5,0,0>, 180, 1.0, 1.0, 0.1, 0.2)

#macro PKG_TSSOP(PKG_PC, PKG_E1)
  #local PKG_A1 = 0.15; // mm
  #local PKG_A2 = 1.05; // mm
  #local PKG_A  = PKG_A1 + PKG_A2; // mm
  #local PKG_b  = 0.30; // mm
  #local PKG_c  = 0.20; // mm
  #local PKG_e  = 0.65; // BSC
  #local PKG_L  = 0.75; // mm
  #local PKG_L1 = 1.05; // REF
  #local PKG_E  = PKG_E1 + 2 * PKG_L1; // mm
  #local PKG_D  = (PKG_PC/2) * PKG_e + 0.1; // mm

  camera {
    location <-6, 8, -6>
    look_at  <0, 0,  0>
    right   x*1 // aspect
  }

  object{ 
    Round_Box_Y (
      <-PKG_D/2, PKG_A1,        -PKG_E1/2>,  // Point_1, Point_2 of outline box
      < PKG_D/2, PKG_A1+PKG_A2,  PKG_E1/2>,  // Point_1, Point_2 of outline box
      PKG_A2/2, // Border_Radius_Big,  // big radius of vertical borders
      PKG_A2/3, // Border_Radius_Small,// small radíus of horizontal borders
      1, // Y_Filled___On,
      0 // Merge___On
    ) 
    texture {
          pigment{ color rgb <1,1,1>*0.03 }
          finish { phong 1  }
    }
  }

  #for (PinIndex, 0, PKG_PC / 2 - 1)
    #local PinX = PKG_e * (PinIndex+0.5) - PKG_D/2;
    microchipPin(<PinX, 0, -PKG_E1/2>, 90, PKG_L1, PKG_A1 + PKG_A2/2 + PKG_c/2, PKG_c, PKG_b)
    microchipPin(<PinX, 0,  PKG_E1/2>, 270, PKG_L1, PKG_A1 + PKG_A2/2 + PKG_c/2, PKG_c, PKG_b)
  #end

#end

#macro PKG_TQFP(PKG_PC)

  #local PKG_e  = 0.50; // mm, pin spacing
  #local PKG_b  = 0.20; // mm, pin width
  #local PKG_L1 = 1.00; // mm, pin length
  #local PKG_c  = 0.20; // mm, pin height
  #local PKG_A1 = 0.10; // mm, ground spacing
  #local PKG_A2 = 0.95; // mm, package height
  #local PKG_D1 = 1.00; // mm, package "oversize" after pins
  
  #local PKG_PPE = PKG_PC/4; // pins per edge
  #local PKG_D2  = (PKG_PPE - 1) * PKG_e; // mm, package space for pins
  #local PKG_D   = PKG_D2 + 2 * PKG_D1; // mm, package edge length

  camera {
    location <-8, 12, -6>
    look_at  <0, 0,  0>
    right   x*1 // aspect
  }

  object{ 
    Round_Box_Y (
      <-PKG_D/2, PKG_A1,        -PKG_D/2>,  // Point_1, Point_2 of outline box
      < PKG_D/2, PKG_A1+PKG_A2,  PKG_D/2>,  // Point_1, Point_2 of outline box
      PKG_A2/2, // Border_Radius_Big,  // big radius of vertical borders
      PKG_D1/2, // Border_Radius_Small,// small radíus of horizontal borders
      1, // Y_Filled___On,
      0 // Merge___On
    ) 
    texture {
          pigment{ color rgb <1,1,1>*0.03 }
          finish { phong 1  }
    }
  }

  #for (PinIndex, 0, PKG_PPE-1)
    #local PinOffset = PKG_e * PinIndex - PKG_D2/2;
    microchipPin(< PKG_D/2, 0, PinOffset>, 0, PKG_L1, PKG_A1 + PKG_A2/2 + PKG_c/2, PKG_c, PKG_b)
    microchipPin(<PinOffset, 0, -PKG_D/2>, 90, PKG_L1, PKG_A1 + PKG_A2/2 + PKG_c/2, PKG_c, PKG_b)
    microchipPin(<-PKG_D/2, 0, PinOffset>, 180, PKG_L1, PKG_A1 + PKG_A2/2 + PKG_c/2, PKG_c, PKG_b)
    microchipPin(<PinOffset, 0,  PKG_D/2>, 270, PKG_L1, PKG_A1 + PKG_A2/2 + PKG_c/2, PKG_c, PKG_b)
  #end

#end
