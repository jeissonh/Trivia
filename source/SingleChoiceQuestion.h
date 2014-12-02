#ifndef SINGLECHOICEQUESTION_H
#define SINGLECHOICEQUESTION_H

#include "Question.h"
#include <vector>

class SingleChoiceQuestion : public Question
{
  protected:
	std::vector<std::string> choices;

  public:
	SingleChoiceQuestion();
	virtual std::istream& load(std::istream& in, bool removeEmptyLine = true) override;
	/// @return true if player gets the right answer
	virtual bool ask() override;
};

#endif // SINGLECHOICEQUESTION_H
