#include "ofApp.h"
#include "Constants.h"
ofApp::ofApp()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 13; ++j)
		{
			m_deck.emplace_back(static_cast<eSuit>(i), static_cast<eValue>(j));
		}
	}
}

//--------------------------------------------------------------
void ofApp::setup()
{
	// Shuffle the deck
	for(int i = 0; i < 52; ++i)
	{
		const int randomIndex = static_cast<int>(ofRandom(0, 52));
		std::swap(m_deck[i], m_deck[randomIndex]);
	}

	DealCards();
	
	ofSetBackgroundColor(33, 91, 0);
}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
	for(const auto& card : m_deck)
	{
		// Outline
		ofSetColor(0);
		ofDrawRectangle(
			card.GetPosition().x, 
			card.GetPosition().y, 
			constants::cardWidth, 
			constants::cardHeight
		);

		// Card
		card.FaceUp() ? ofSetColor(255) : ofSetColor(153, 0, 0);
		
		ofDrawRectangle(
			card.GetPosition().x + constants::outlineWidth, 
			card.GetPosition().y + constants::outlineWidth, 
			constants::cardWidth - 2 * constants::outlineWidth, 
			constants::cardHeight - 2 * constants::outlineWidth
		);

		if (card.FaceUp())
		{
			// Colour
			ofSetColor(card.GetColour());
			ofDrawBitmapString(
				card.GetValue(),
				card.GetPosition().x + constants::cardWidth / 2 - constants::outlineWidth,
				card.GetPosition().y + constants::cardHeight / 2 + constants::outlineWidth
			);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

void ofApp::DealCards()
{
	int card = 0;
	for(int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			m_deck[card].SetPosition({ 
				static_cast<float>(i * constants::cardWidth) + i * 10,
				static_cast<float>(constants::screenHeight) / 4.f + j * (constants::cardHeight / 4)
			});

			if(j == i - 1)
			{
				m_deck[card].Reveal();
			}
			
			card++;
		}
	}
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
