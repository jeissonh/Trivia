#ifndef SINGLECHOICEQUESTION_H
#define SINGLECHOICEQUESTION_H

#include "Question.h"
#include <QVector>

class GraphicsSingleChoiceQuestionItem;

class SingleChoiceQuestion : public Question
{
	friend class GraphicsSingleChoiceQuestionItem;

  protected:
	QVector<QString> choices;

  public:
	SingleChoiceQuestion();
	virtual QTextStream& load(QTextStream& in, bool removeEmptyLine = true) override;
	/// @return true if player gets the right answer
	virtual bool ask() override;
	virtual GraphicsQuestionItem* buildGraphicsQuestionItem() override;
};


class GraphicsSingleChoiceQuestionItem : public GraphicsQuestionItem
{
  public:
	explicit GraphicsSingleChoiceQuestionItem(Question* question) : GraphicsQuestionItem(question) { }
	virtual ~GraphicsSingleChoiceQuestionItem() { }
};

#endif // SINGLECHOICEQUESTION_H
