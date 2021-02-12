#include "PlayingCard.h"

#include "Constants.h"

PlayingCard::PlayingCard(const eSuit suit, const eValue value) :
	m_suit(suit),
	m_value(value)
{
	m_position.x = constants::screenWidth - constants::cardWidth - constants::outlineWidth;
	m_position.y = constants::outlineWidth;
}

ofColor PlayingCard::GetColour() const
{
	switch (m_suit)
	{
	case eSuit::e_Hearts:
	case eSuit::e_Diamonds:
		return { 255, 0, 0 };
		break;
	case eSuit::e_Clubs:
	case eSuit::e_Spades:
		return { 0, 0, 0 };
		break;
	}

	return {};
}

ofVec2f PlayingCard::GetPosition() const
{
	return m_position;
}

void PlayingCard::SetPosition(const ofVec2f& vec)
{
	m_position = vec;
}

std::string PlayingCard::GetValue() const
{
	switch (m_value)
	{
		case eValue::e_Ace:
			return "A";
			break;
		case eValue::e_Two: 
			return "2";
			break;
		case eValue::e_Three: 
			return "3";
			break;
		case eValue::e_Four: 
			return "4";
			break;
		case eValue::e_Five: 
			return "5";
			break;
		case eValue::e_Six: 
			return "6";
			break;
		case eValue::e_Seven: 
			return "7";
			break;
		case eValue::e_Eight: 
			return "8";
			break;
		case eValue::e_Nine: 
			return "9";
			break;
		case eValue::e_Ten: 
			return "10";
			break;
		case eValue::e_Jack: 
			return "J";
			break;
		case eValue::e_Queen: 
			return "Q";
			break;
		case eValue::e_King: 
			return "K";
			break;
	}
	return "ERROR";
}
