#include <complex>
#include <cstdio>

int MandelbrotCalculate(std::complex<double> c, int maxiter)
{
	// iterates z = z + c until |z| >= 2 or maxiter is reached,
	// returns the number of iterations.
	std::complex<double> z = c;
	int n=0;
	for(; n<maxiter; ++n)
	{
		if( std::abs(z) >= 2.0) break;
		z = z*z + c;
	}
	return n;
}

int main()
{
	const int width = 78, height = 44, num_pixels = width*height;
	const std::complex<double> center(-.7, 0), span(2.7, -(4/3.0)*2.7*height/width);
	const std::complex<double> begin = center-span/2.0;
	const int maxiter = 100000;

	#pragma omp parallel for ordered schedule(dynamic)
	for(int pix=0; pix<num_pixels; ++pix)
	{
		const int x = pix%width, y = pix/width;
		std::complex<double> c = begin + std::complex<double>(x * span.real() / (width +1.0), y * span.imag() / (height+1.0));
         
		int n = MandelbrotCalculate(c, maxiter);
		if(n == maxiter) n = 0;

		#pragma omp ordered
		{
			char c = ' ';
			if(n > 0)
			{
				static const char charset[] = ".,c8M@jawrpogOQEPGJ";
				c = charset[n % (sizeof(charset)-1)];
			}
			std::putchar(c);
			if(x+1 == width) std::puts("|");
		}
	}
}
