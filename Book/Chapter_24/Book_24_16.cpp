template<class Scalar>
class complex
{
	Scalar re, im;
public:
	constexpr complex(const Scalar& r, const Scalar& i):
		re{ r },
		im{ i }
	{}
	constexpr complex(const Scalar& r):
		re{ r },
		im{ Scalar() }
	{}
	complex():
		re{ Scalar() },
		im{ Scalar() }
	{}
	constexpr Scalar real()
	{
		return re;
	}
	constexpr Scalar imag()
	{
		return im;
	}
};

using cmplx = complex<double>;
void f(cmplx z, vector<cmplx>& vc)
{
	cmplx z2 = pow(z, 2);
	cmplx z3 = z2 * 9.3 + vc[3];
	cmplx sum = accumulate(vc.begin(), vc.end(); cmplx());
}