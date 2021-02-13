#pragma once
#include <ofColor.h>
#include <ostream>
#include <ofVec2f.h>

enum class eSuit
{
	e_Hearts,
	e_Diamonds,
	e_Clubs,
	e_Spades
};

enum class eValue
{
	e_Ace,
	e_Two,
	e_Three,
	e_Four,
	e_Five,
	e_Six,
	e_Seven,
	e_Eight,
	e_Nine,
	e_Ten,
	e_Jack,
	e_Queen,
	e_King
};

class PlayingCard
{
public:
	PlayingCard(eSuit suit, eValue value);
	ofColor GetColour() const;

	ofVec2f GetPosition() const;
	void SetPosition(const ofVec2f& vec);

	std::string GetValue() const;

	bool FaceUp() const;
	void Reveal();

private:
	eSuit m_suit;
	eValue m_value;
	ofVec2f m_position;

	bool m_faceUp;
};
