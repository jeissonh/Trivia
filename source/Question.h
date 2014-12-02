#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
#include <string>

class Question
{
  protected:
	std::string text;
	std::string answer;

  public:
	Question();
	virtual ~Question() {}
	friend inline std::istream& operator>>(std::istream& in, Question& question) { return question.load(in); }
	virtual std::istream& load(std::istream& in, bool removeEmptyLine = true);

	friend inline std::ostream& operator<<(std::ostream& out, const Question& question)
	{
		out << '[' << question.text << ']' << std::endl;
		return out << '{' << question.answer << '}' << std::endl;
	}

	/// @return true if player gets the right answer
	virtual bool ask() = 0; // pure virtual method
};

#endif // QUESTION_H
