// BoostSharp.h
#define BOOST_REGEX_NO_LIB

#include <string>
#include <boost/regex.hpp>
#include <msclr\marshal_cppstd.h>
#pragma once

using namespace System;

namespace BoostSharp {

	[Flags]
	public enum class MatchFlags
	{
		None = 0,
		I = 1,
		M = I << 1,
		G = M << 1
	};
	public ref class Regex
	{

	public:

		static String^ Replace(String^ text, String^ regex, String^ formatString, MatchFlags flags)
		{
			msclr::interop::marshal_context context;
			std::string testStr = context.marshal_as<std::string>(text);
			std::string regexStr = context.marshal_as<std::string>(regex);
			std::string formatStr = context.marshal_as<std::string>(formatString);

			boost::match_flag_type boostFlags(boost::match_flag_type::match_default);

			if(!flags.HasFlag(MatchFlags::G)){
				boostFlags = boostFlags | boost::match_flag_type::format_first_only; 
			}
			
			if(flags.HasFlag(MatchFlags::M)){
				boostFlags = boostFlags | boost::match_flag_type::match_single_line; 
			}
			boostFlags = boostFlags | boost::match_flag_type::format_all;

			boost::regex::flag_type regexFlags (boost::regex::perl);
			if(flags.HasFlag(MatchFlags::I)){
				regexFlags = regexFlags | boost::regex::icase; 
			}
		//	std::string str = "John Doe";

			boost::regex re(regexStr,regexFlags);
			std::string res =boost::regex_replace(testStr, re, formatStr, boostFlags) ;
			String^ result;
			result = context.marshal_as<String^>( res );
		//	String^ result = boost::regex_replace(str, re, "=") ;
			return result;
		}
	};
}
