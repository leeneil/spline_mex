// spline.cpp : 定義 DLL 應用程式的匯出函式。
//

#include <gsl/gsl_spline.h>


void spline(double *YY, 
		double *X, double *Y, double *XX, int m1, int m2) {

	// m1: length of discrete extremas
	// m2: length of original data points

	gsl_interp_accel *acc = gsl_interp_accel_alloc ();
  	const gsl_interp_type *t = gsl_interp_cspline; 
  	gsl_spline *spline = gsl_spline_alloc (t, m1);

	/* Core function */

  	gsl_spline_init (spline, X, Y, m1);

	double m;
	
	if (m1 > 2 ) {
		for (int j = 0; j < m2; j++) {
			YY[j] = gsl_spline_eval (spline, XX[j], acc);
		} // end of for-j
	} // end of if

	else {
		m = (Y[1] - Y[0]) / (X[1] - X[0]);
		for (int j = 0; j < m2; j++) {
			YY[j] = Y[0] + m * (XX[j] - X[0]);		
		} // end of for-j
	} //end of else

	// delete[] xd;
	gsl_spline_free (spline);
  	gsl_interp_accel_free (acc);

}
