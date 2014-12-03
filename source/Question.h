#ifndef QUESTION_H
#define QUESTION_H

#include <QTextStream>
#include <QGraphicsRectItem>

class GraphicsQuestionItem;

class Question
{
	Q_DISABLE_COPY(Question)
	friend class GraphicsQuestionItem;

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
	virtual GraphicsQuestionItem* buildGraphicsQuestionItem() = 0;
};

class GraphicsQuestionItem : public QGraphicsRectItem
{
  protected:
	Question* question;

  public:
	explicit GraphicsQuestionItem(Question* question) : question(question) { }
	virtual ~GraphicsQuestionItem() { /* this object does not own question, do not delete it */ }
};

#endif // QUESTION_H
