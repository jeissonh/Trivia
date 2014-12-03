#ifndef TEXTUALQUESTION_H
#define TEXTUALQUESTION_H

#include "Question.h"

class GraphicsTextualQuestionItem;

class TextualQuestion : public Question
{
	friend class GraphicsTextualQuestionItem;

  public:
	TextualQuestion();
	virtual bool ask() override;
	virtual GraphicsQuestionItem* buildGraphicsQuestionItem() override;
};

class GraphicsTextualQuestionItem : public GraphicsQuestionItem
{
  public:
	explicit GraphicsTextualQuestionItem(Question* question) : GraphicsQuestionItem(question) { }
	virtual ~GraphicsTextualQuestionItem() { }
};

#endif // TEXTUALQUESTION_H
