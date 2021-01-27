#ifndef TASK_23_02_MAIL_FILE_H
#define TASK_23_02_MAIL_FILE_H

#ifndef TASK_23_02_STDAFX_H
#include "Task_23_02_stdafx.h"
#endif

using Line_iter = std::vector<std::string>::const_iterator;

class Message
{
private:
	Line_iter first;
	Line_iter last;
public:
	Message(Line_iter p1, Line_iter p2);
	Line_iter begin() const;
	Line_iter end() const;
};

typedef std::vector<Message>::const_iterator Mess_iter;

bool find_message_end(Line_iter line);
int is_prefix(const std::string& s, const std::string& p);
bool find_subject(const Message* m, std::string& subject);
bool find_from_addr(const Message* m, std::string& s);

class Mail_file
{
private:
	std::string name;
	std::vector<std::string> lines;
	std::vector<Message> m;
public:
	Mail_file(const std::string& fileName);
	Mess_iter begin() const;
	Mess_iter end() const;
};

#endif