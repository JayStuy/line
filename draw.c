#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"


//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int x,y;
  //quadrant 1
  if( x0 >= 0 && x1 >= 0 && y0 >= 0 && y1 >= 0 ) {
    x = x0;
    y = y0;
    //octant 1
    if( x <= y ) {
      int A, B, d;
      A = y1 - y0;
      B = -1*(x1 - x0);
      d = 2*A + B;

      while( x <= x1 ){
	plot( s, c, x, y );
	if( d > 0 ) {
	  y ++;
	  d += 2*B;
	}
	x ++;
	d += 2*A;
      }
    } 
    //octant 2
    else {
      int A, B, d;
      A = y1 - y0;
      B = -1*(x1 - x0);
      d = (1 / 2)*A + B;

      while( y <= y1 ) {
	plot( s, c, x, y );
	if( d < 0 ) {
	  x ++;
	  d += 2*A;
	}
	y ++;
	d += 2*B;
      }
    }
  }

  //quadrant 3
  else if( x0 <= 0 && x1 <= 0 && y0 <= 0 && y1 <= 0 ) {
    x = x1;
    y = y1;
    //octant 5
    if( x <= y ) {
      int A, B, d;
      A = y0 - y1;
      B = -1*(x0 - x1);
      d = 2*A + B;

      while( x < x0 ){
        plot( s, c, x, y );
	if( d > 0 ) {
          y ++;
          d += 2*B;
        }
	x ++;
	d += 2*A;
      } 
    }
    //octant 6
    else {
      int A, B, d;
      A = y0 - y1;
      B = -1*(x0 - x1);
      d = 1 / 2* A + B;

      while( y < y0 ) {
	plot( s, c, x, y );
	if( d < 0 ) {
          x ++;
          d += 2*A;
        }
	y ++;
	d += 2*B;
      } 
    }
  }

  else if( x0 >= 0 && x1 >= 0 && y0 <= 0 && y1 < 0 ){
    x = x0;
    y = y0;
    if( x*-1 >= y ) {
      int A, B, d;
      A = y0 - y1;
      B = -1*(x1 - x0);
      d = 2*A + B;

      while( x < x1 ){
        plot( s, c, x, y );
	if( d > 0 ) {
          y --;
          d += 2*B;
        }
	x ++;
	d += 2*A;
      } 
    }
    else {
      int A, B, d;
      A = y1 - y0;
      B = -1*(x1 - x0);
      d = 1 / 2* A + B;

      while( y > y1 ) {
	plot( s, c, x, y );
	if( d < 0 ) {
          x ++;
          d += 2*A;
        }
	y --;
	d += 2*B;
      } 
    }
  }

  else {
    x = x1;
    y = y1;
    if( x*-1 <= y ) {
      int A, B, d;
      A = y1 - y0;
      B = -1*(x0 - x1);
      d = 2*A + B;

      while( x > x1 ){
        plot( s, c, x, y );
        if( d > 0 ) {
          y ++;
          d += 2*B;
        }
        x --;
        d += 2*A;
      }
    }
    else {
      int A, B, d;
      A = y1 - y0;
      B = -1*(x0 - x1);
      d = 1 / 2* A + B;

      while( y < y1 ) {
        plot( s, c, x, y );
        if( d < 0 ) {
          x --;
          d += 2*A;
        }
        y ++;
        d += 2*B;
      }
    }
  }
}

