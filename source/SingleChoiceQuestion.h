#ifndef SINGLECHOICEQUESTION_H
#define SINGLECHOICEQUESTION_H

#include "Question.h"
#include <QVector>

class SingleChoiceQuestion : public Question
{
  protected:
	QVector<QString> choices;

  public:
	SingleChoiceQuestion();
	virtual QTextStream& load(QTextStream& in, bool removeEmptyLine = true) override;
	/// @return true if player gets the right answer
	virtual bool ask() override;
};

#endif // SINGLECHOICEQUESTION_H
