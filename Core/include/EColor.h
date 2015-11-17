#ifndef ECHOES_COLOR_H
#define ECHOES_COLOR_H

#include "EPrerequisites.h"
#include <exception>

#pragma warning(push)
#pragma warning(disable: 4244)

namespace Echoes {
	class ECHOES_EXPORT Color
	{
	public:
		//************************************
		// Create a color from float RGBA 
		// values from 0 to 1.
		//************************************
		Color(const float& r, const float& g, const float& b, float a = 1.0f) {
			mRGB << r, g, b, a;
		}

		//*************************************
		// Create a color from integral RGBA 
		// values from 0 to 255.
		//*************************************
		Color(const int& r, const int& g, const int& b, int a = 255) {
			mRGB << r, g, b, a;
			mRGB /= 255.0f;

		}

		//*************************************
		// Create a color from a hexadecimal
		// RGB integer.
		//*************************************
		Color(const int& hex) {
			mRGB << 
				((hex >> 16) & 0xFF),			// R
				((hex >> 8) & 0xFF),			// G
				(hex& 0xFF),					// B
				255.0f;							// A
			mRGB /= 255.0f;
		}

		const float fr() const { return mRGB(0); }
		const float fg() const { return mRGB(1); }
		const float fb() const { return mRGB(2); }
		const float fa() const { return mRGB(3); }

		const int ir() const { return mRGB(0) * 255; }
		const int ig() const { return mRGB(1) * 255; }
		const int ib() const { return mRGB(2) * 255; }
		const int ia() const { return mRGB(3) * 255; }


	protected:
		Eigen::Vector4f	mRGB;
	};
}

#pragma warning(pop)
#endif // ECHOES_COLOR_H