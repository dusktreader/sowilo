#pragma once

class SowiloException : public std::exception
{
private:
    std::string message;
public:
    SowiloException( std::string="Sowilo Error" ) : message(message){}
    ~SowiloException() throw(){}
    virtual const char* what() const throw(){ return message.c_str(); }
};
