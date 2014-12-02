#ifndef TEXTUALQUESTION_H
#define TEXTUALQUESTION_H

#include "Question.h"

class TextualQuestion : public Question
{
  public:
	TextualQuestion();
	virtual bool ask() override;
};

#endif // TEXTUALQUESTION_H
