#ifndef NUMERICQUESTION_H
#define NUMERICQUESTION_H

#include "Question.h"

class GraphicsNumericQuestionItem;

class NumericQuestion : public Question
{
	friend class GraphicsNumericQuestionItem;

  public:
	NumericQuestion();
	virtual bool ask() override;
	virtual GraphicsQuestionItem* buildGraphicsQuestionItem() override;
};

class GraphicsNumericQuestionItem : public GraphicsQuestionItem
{
  public:
	explicit GraphicsNumericQuestionItem(Question* question) : GraphicsQuestionItem(question) { }
	virtual ~GraphicsNumericQuestionItem() { }
};

#endif // NUMERICQUESTION_H
