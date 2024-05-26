// POV-Ray 3.6/3.7 include file "Round_Box_Y.inc"                                                                                                                                                // PoVRay 3.6 include File "wheel_000.inc"
// author: Friedrich A, Lohmueller, July-2016
// homepage: http://www.f-lohmueller.de/
//---------------------------------------------------------------------------------------
#ifndef( Round_Box_Y_Inc_Temp)
#declare Round_Box_Y_Inc_Temp = version;
#version 3.6;
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
#ifndef(  Shapes_Inc_Temp)
#include "shapes.inc"                                             
#end 
#ifndef(  Shapes3_Inc_Temp)
#include "shapes3.inc"                                             
#end
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
#macro Round_Box_Y (  R_Point_1_In, R_Point_2_In,         // box outline
                      Border_Radius_Big,    // radius around vertical edges 
                      Border_Radius_Small,  // radius around horizontal edges
                      Y_Filled___On, // 
                      Merge___On
                   ) //------------------------
//---------------------------------------------
#local D = 0.0000001;  // a very little bit to avoid coincident surfaces!!!

//---------------------------------------------

#if ( abs(Border_Radius_Big) >= abs(Border_Radius_Small))
#local Rmaj = abs(Border_Radius_Big); 
#local Rmin = abs(Border_Radius_Small); 
#end 

#if ( abs(Border_Radius_Big) < abs(Border_Radius_Small)) 
 #warning "\nRound_Box_Y()macro  \n called Border_Radius_Big < Border_Radius_Small,\nradi interchanged\n"
#local Rmaj = abs(Border_Radius_Small); 
#local Rmin = abs(Border_Radius_Big); 
#end 

#if ((Y_Filled___On = 0) & ( Rmaj < 2*Rmin)) // for non filled version
 #local  Rmin = Rmaj/2 - D; 
#end  

#if (Rmin   = 0)
 #local Rmin = 2*D;
#end

// --------------------------------------------------------------
#if ( 2*Rmaj >  (R_Point_2_In.x-R_Point_1_In.x) ) 
#warning "\nRound_Box_Y() macro called with bad x-size:  width in x < 2*Radius_big. Results may not be as expected\n"
#end 

#if ( (2*Rmin) >  (R_Point_2_In.y-R_Point_1_In.y) )     
#warning "\nRound_Box_Y() macro called with bad y-size:  width in y < 2*Radius_big. Results may not be as expected\n"
#end 

#if ( 2*Rmaj >  (R_Point_2_In.z-R_Point_1_In.z) ) 
#warning "\nRound_Box_Y() macro called with bad z-size:  width in z < 2*Radius_small. Results may not be as expected\n"
#end 
// --------------------------------------------------------------
// right order of the coordinates:
#local P1 = < min(R_Point_1_In.x,R_Point_2_In.x),
                 min(R_Point_1_In.y,R_Point_2_In.y), 
                    min(R_Point_1_In.z,R_Point_2_In.z)>;  
#local P2 = < max(R_Point_1_In.x,R_Point_2_In.x, min(R_Point_1_In.x,R_Point_2_In.x)+2*Rmaj),
                 max(R_Point_1_In.y,R_Point_2_In.y, min(R_Point_1_In.y,R_Point_2_In.y)+2*Rmin), 
                    max(R_Point_1_In.z,R_Point_2_In.z, min(R_Point_1_In.z,R_Point_2_In.z)+2*Rmaj)>; 



//-----------------------------------------------------
#if (Rmin > D)
#local Quarter_1 = 
//#macro Segment_of_Torus( R_major, R_minor, Segment_Angle)
object{ Segment_of_Torus( Rmaj-Rmin, Rmin, 90)
        rotate<0,90,0> translate<Rmaj,0,Rmaj>
      } // end of Torus_Segment(...) -----------------------              
#end
     
     


//---------------------------------------------------------
#if (Merge___On = 1)  // 1
 merge{   // outer union/merge
#else 
 union{ 
#end 

#if (Y_Filled___On = 0)  // than with difference: 
 difference{
#end 


#if (Merge___On = 1)  // 2   inner union/m
 merge{ 
#else 
 union{ 
#end 

// cross for flat faces
box{ P1+< 0     , Rmin-D, Rmaj-D>,P2+<-0     ,-Rmin+D,-Rmaj+D>} //  x
box{ P1+< Rmin  , 0     , Rmaj-D>,P2+<-Rmin  ,-0     ,-Rmaj+D>} //  y
box{ P1+< Rmaj-D, Rmin  , 0     >,P2+<-Rmaj+D,-Rmin  , 0     >} //  z
 
#if ((Rmin > D)  & (Y_Filled___On = 1)) 
 // inner faces
box{ P1+< Rmin  , 0-D    , Rmaj-D>,P2+<-Rmin  , 0+D    ,-Rmaj+D>} //  x
box{ P1+< Rmaj  , Rmin , Rmaj-D>,P2+<-Rmaj  ,-Rmin ,-Rmaj+D>} //  y
box{ P1+< Rmaj-D, D    , Rmin  >,P2+<-Rmaj+D,-D    ,-Rmin  >} //  z
#end // of #if ((Rmin > D)  & (Y_Filled___On = 1))           
 


//union{  // vertical big cylinders outside
cylinder{ <P1.x+Rmaj-D, P1.y+Rmin-D, P1.z+Rmaj>,
          <P1.x+Rmaj-D, P2.y-Rmin+D, P1.z+Rmaj>, Rmaj} 
cylinder{ <P1.x+Rmaj-D, P1.y+Rmin-D, P2.z-Rmaj>,
          <P1.x+Rmaj-D, P2.y-Rmin+D, P2.z-Rmaj>, Rmaj} 
 
cylinder{ <P2.x-Rmaj, P1.y+Rmin-D, P1.z+Rmaj>,
          <P2.x-Rmaj, P2.y-Rmin+D, P1.z+Rmaj>, Rmaj} 
cylinder{ <P2.x-Rmaj, P1.y+Rmin-D, P2.z-Rmaj>,
          <P2.x-Rmaj, P2.y-Rmin+D, P2.z-Rmaj>, Rmaj} 
 
//}  

#if (Y_Filled___On = 1)  // 
//union{//  vertical smaller cylinders inside
cylinder{ <P1.x+Rmaj, P1.y-1*D, P1.z+Rmaj>,
          <P1.x+Rmaj, P2.y+1*D, P1.z+Rmaj>, Rmaj-Rmin} 
cylinder{ <P1.x+Rmaj, P1.y-1*D, P2.z-Rmaj>,
          <P1.x+Rmaj, P2.y+1*D, P2.z-Rmaj>, Rmaj-Rmin} 

cylinder{ <P2.x-Rmaj, P1.y-D, P1.z+Rmaj>,
          <P2.x-Rmaj, P2.y+D, P1.z+Rmaj>, Rmaj-Rmin} 
cylinder{ <P2.x-Rmaj, P1.y-D, P2.z-Rmaj>,
          <P2.x-Rmaj, P2.y+D, P2.z-Rmaj>, Rmaj-Rmin} 
//pigment {Magenta}
//} 
#end 


scale<1,1,1>  rotate<0, 0,0> translate<0,0,0>
}  // // end of inner union/merge  // 2 ----------------------------------------------------
 









#if ((Rmin > D)  & (Y_Filled___On = 0)) 
 // faces
 // 
 box{ <P1.x+ 2*Rmin  , P1.y-D, P1.z+  Rmaj-D>, <P2.x -2*Rmin  , P2.y+D, P2.z  -Rmaj+D>} // in x
 box{ <P1.x+   Rmaj-D, P1.y-D, P1.z+2*Rmin  >, <P2.x   -Rmaj+D, P2.y+D, P2.z-2*Rmin  >} // in z
 // up
 box{ <P1.x+Rmin  ,P2.y-Rmin+D,P1.z+Rmaj-D>,<P2.x-Rmin  , P2.y+2*D,P2.z-Rmaj+D>} // in x
 box{ <P1.x+Rmaj-D,P2.y-Rmin+D,P1.z+Rmin  >,<P2.x-Rmaj+D, P2.y+2*D,P2.z-Rmin  >} // in z
 // down
 box{ <P1.x+Rmin  ,P1.y+Rmin-D,P1.z+Rmaj-D>,<P2.x-Rmin  , P1.y-2*D,P2.z-Rmaj+D>} // in x
 box{ <P1.x+Rmaj-D,P1.y+Rmin-D,P1.z+Rmin  >,<P2.x-Rmaj+D, P1.y-2*D,P2.z-Rmin  >} // in z
 //edges
#end//



#if ((Rmin > D)  & (Y_Filled___On = 0))
  // thin inside 
 union{// 
 cylinder{ <P1.x+Rmaj, P1.y-2*D, P1.z+Rmaj>,
           <P1.x+Rmaj, P2.y+2*D, P1.z+Rmaj>, Rmaj-2*Rmin} 
 cylinder{ <P1.x+Rmaj, P1.y-2*D, P2.z-Rmaj>,
           <P1.x+Rmaj, P2.y+2*D, P2.z-Rmaj>, Rmaj-2*Rmin} 
   
 cylinder{ <P2.x-Rmaj, P1.y-2*D, P1.z+Rmaj>,
           <P2.x-Rmaj, P2.y+2*D, P1.z+Rmaj>, Rmaj-2*Rmin} 
 cylinder{ <P2.x-Rmaj, P1.y-2*D, P2.z-Rmaj>,
           <P2.x-Rmaj, P2.y+2*D, P2.z-Rmaj>, Rmaj-2*Rmin} 
 //pigment { Red} 
 } 
#end // #if ((Rmin > D)  & (Y_Filled___On = 0))
//-----------------------------------

union{// inside
 cylinder{ <P1.x+Rmaj, P1.y-2*D     , P1.z+Rmaj>,
           <P1.x+Rmaj, P1.y+Rmin-D, P1.z+Rmaj>, Rmaj-Rmin} 
 cylinder{ <P1.x+Rmaj, P1.y-2*D     , P2.z-Rmaj>,
           <P1.x+Rmaj, P1.y+Rmin-D, P2.z-Rmaj>, Rmaj-Rmin} 
   
 cylinder{ <P2.x-Rmaj, P1.y-2*D     , P1.z+Rmaj>,
           <P2.x-Rmaj, P1.y+Rmin-D, P1.z+Rmaj>, Rmaj-Rmin} 
 cylinder{ <P2.x-Rmaj, P1.y-2*D     , P2.z-Rmaj>,
           <P2.x-Rmaj, P1.y+Rmin-D, P2.z-Rmaj>, Rmaj-Rmin} 
 } 
#if (Rmin > D)
  // upside
 union{// inside
 cylinder{ <P1.x+Rmaj, P2.y-Rmin+D, P1.z+Rmaj>,
           <P1.x+Rmaj, P2.y+2*D     , P1.z+Rmaj>, Rmaj-Rmin} 
 cylinder{ <P1.x+Rmaj, P2.y-Rmin+D, P2.z-Rmaj>,
           <P1.x+Rmaj, P2.y+2*D     , P2.z-Rmaj>, Rmaj-Rmin} 
   
 cylinder{ <P2.x-Rmaj, P2.y-Rmin+D, P1.z+Rmaj>,
           <P2.x-Rmaj, P2.y+2*D     , P1.z+Rmaj>, Rmaj-Rmin} 
 cylinder{ <P2.x-Rmaj, P2.y-Rmin+D, P2.z-Rmaj>,
           <P2.x-Rmaj, P2.y+2*D     , P2.z-Rmaj>, Rmaj-Rmin} 
 } 
#end 

#if (Y_Filled___On = 0)  // than with difference: 
} // end of difference 
#end 

// -------------------------


 
//#if (Rmin > D)
union{ // horizontal small border cylinders
cylinder{ <P1.x+Rmin,P1.y+Rmin,P1.z+Rmaj-D>,<P1.x+Rmin,P1.y+Rmin,P2.z-Rmaj+D>, Rmin } 
cylinder{ <P1.x+Rmin,P2.y-Rmin,P1.z+Rmaj-D>,<P1.x+Rmin,P2.y-Rmin,P2.z-Rmaj+D>, Rmin} 
cylinder{ <P2.x-Rmin,P1.y+Rmin,P1.z+Rmaj-D>,<P2.x-Rmin,P1.y+Rmin,P2.z-Rmaj+D>, Rmin} 
cylinder{ <P2.x-Rmin,P2.y-Rmin,P1.z+Rmaj-D>,<P2.x-Rmin,P2.y-Rmin,P2.z-Rmaj+D>, Rmin} 

cylinder{ <P1.x+Rmaj-D,P1.y+Rmin,P1.z+Rmin>,<P2.x-Rmaj+D,P1.y+Rmin,P1.z+Rmin>, Rmin } 
cylinder{ <P1.x+Rmaj-D,P2.y-Rmin,P1.z+Rmin>,<P2.x-Rmaj+D,P2.y-Rmin,P1.z+Rmin>, Rmin} 
cylinder{ <P1.x+Rmaj-D,P1.y+Rmin,P2.z-Rmin>,<P2.x-Rmaj+D,P1.y+Rmin,P2.z-Rmin>, Rmin} 
cylinder{ <P1.x+Rmaj-D,P2.y-Rmin,P2.z-Rmin>,<P2.x-Rmaj+D,P2.y-Rmin,P2.z-Rmin>, Rmin} 
 // pigment {color rgb<1,0.7,0>} 

}
//#end

// edges curved
object{ Quarter_1  rotate<0, 0*90,0> translate<P1.x,P1.y+Rmin,P1.z> }
object{ Quarter_1  rotate<0, 0*90,0> translate<P1.x,P2.y-Rmin,P1.z> }

object{ Quarter_1  rotate<0,-1*90,0> translate<P2.x,P1.y+Rmin,P1.z> }
object{ Quarter_1  rotate<0,-1*90,0> translate<P2.x,P2.y-Rmin,P1.z> }

object{ Quarter_1  rotate<0,-2*90,0> translate<P2.x,P1.y+Rmin,P2.z> }
object{ Quarter_1  rotate<0,-2*90,0> translate<P2.x,P2.y-Rmin,P2.z> }

object{ Quarter_1  rotate<0,-3*90,0> translate<P1.x,P1.y+Rmin,P2.z> }
object{ Quarter_1  rotate<0,-3*90,0> translate<P1.x,P2.y-Rmin,P2.z> }
//#end
 

}// end of outer union/merge   // 1
#end// of macro ------------------------------------------------------// end of macro




//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
// sample: 
/*
//----------------------------------------------------------------------------- textures
#declare Round_Box_Y_Texture = 
   texture { //Chrome_Metal}  
             pigment{ color rgb<1,1,1> } 
             finish { phong 0.1} 
           } // end of texture
//---------------------------------------------------------------------------------------
//------------------------------------------------------------------------- 
#include "Round_Box_Y.inc"
//------------------------------------------------------------------------- 
object{ Round_Box_Y( <0,0,0>, <1,0.5, 1.5>, //  R_Point_1, R_Point_2,         // box outline
                     0.30, // Border_Radius_Big,    // radius around vertical edges 
                     0.10, // Border_Radius_Small,  // radius around horizontal edges
                     1, // Y_Filled___On,
                     0 // Merge___On -
                   ) //----------------------------------------------
         texture{ Round_Box_Y_Texture} 
         scale<1,1,1>  rotate< 0, 0,0> translate<0,0.0,0>
  }//---------------------------------------------------------------------- 
//-------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
*/


#version Round_Box_Y_Inc_Temp;
#end
//------------------------------------- end of include file
