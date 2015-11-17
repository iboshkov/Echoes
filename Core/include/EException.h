#ifndef ECHOES_EXCEPTION_H
#define ECHOES_EXCEPTION_H

#include <exception>
#include "EPrerequisites.h"
namespace Echoes {
	 
	class ECHOES_EXPORT Exception : public std::exception
	{
	public:
		Exception(int code, const String& description, const String& source, const char* type, const char* file, long line) {

		}

		enum ExceptionCodes {
			ERR_DEFAULT
		};	

		long getLine() const { return mLine; }
		int getCode() const { return mCode; }
		const String& getTypeName() const { return mTypeName; }
		const String& getSource() const { return mSource; }
		const String& getFile() const { return mFile; }
		const String& getDescription() const { return mDescription; }
	protected:
		long mLine;
		int mCode;
		String mTypeName;
		String mDescription;
		String mSource;
		String mFile;
	};

	class ExceptionFactory
	{
	private:
		/// Private constructor, no construction
		ExceptionFactory() {}
	public:
		static ECHOES_NORETURN void throwException(
			Exception::ExceptionCodes code, int number,
			const String& desc,
			const String& src, const char* file, long line)
		{
			switch (code)
			{
			default: throw Exception(number, desc, src, "Exception", file, line);
			}
		}

	};
}
#ifndef ECHOES_EXCEPT
#	define ECHOES_EXCEPT(number, desc, src) Echoes::ExceptionFactory::throwException(number, number, desc, src, __FILE__, __LINE__)
#endif 
#endif // ECHOES_CORE_H