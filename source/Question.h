#ifndef QUESTION_H
#define QUESTION_H

#include <QTextStream>

class Question
{
  protected:
	QString text;
	QString answer;

  public:
	Question();
	virtual ~Question() {}
	friend inline QTextStream& operator>>(QTextStream& in, Question& question) { return question.load(in); }
	virtual QTextStream& load(QTextStream& in, bool removeEmptyLine = true);

	friend inline QTextStream& operator<<(QTextStream& out, const Question& question)
	{
		out << '[' << question.text << ']' << endl;
		return out << '{' << question.answer << '}' << endl;
	}

	/// @return true if player gets the right answer
	virtual bool ask() = 0; // pure virtual method
};

#endif // QUESTION_H
