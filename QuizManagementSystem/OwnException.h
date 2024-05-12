#pragma once


/*


--------   BAX ISTIFADESI BELEDI

	if (!file.is_open() || !file)
		throw Exception("\nFile Achilmadi.", GetTime(), __FILE__, __LINE__);

		\n den sonrasini ozun yazirsan. qalanlari qalir.

*/



// Get Current Time in Text (string).

#pragma once

#include <string>
#include <ctime>
#include <iostream>

std::string GetTime()
{
    char* dt = nullptr;
    try
    {
        time_t now;
        time(&now);

        dt = new char[26];
        ctime_s(dt, 26, &now);
    }
    catch (std::exception& ex)
    {
        system("cls");
        std::cout << ex.what() << std::endl;
        system("pause");
    }

    return std::string(dt);
}

class Exception : public std::exception
{
    std::string _text = "";
    std::string _time = "";
    std::string _source = "";
    size_t _line = 0;
    std::string _completed_message = "";

public:
    Exception(std::string Text, std::string Time, std::string Source, size_t Line)
        : std::exception(Text.c_str()), _text(Text), _time(Time), _source(Source), _line(Line)
    {
        this->_completed_message
            = "\n\n\t---  Description of Exception  ---" + _text
            + "\n--  Exception Source :  " + _source
            + "\n--  Exception Time :  " + _time
            + "--  Exception Line :  " + std::to_string(_line)
            + "\n\n\n";
    }

    std::string Get_Message() const
    {
        return this->_completed_message;
    }

    char const* what() const noexcept override
    {
        return this->_completed_message.c_str();
    }
};
