#ifndef TEXT_CINEMATIC_PANEL_H
#define TEXT_CINEMATIC_PANEL_H

#include <functional>
#include <vector>

#include "Panel.h"

// Very similar to a cinematic panel, only now it's designed for cinematics with
// subtitles at the bottom (a.k.a., "text").

// A vector of doubles is used for timing the text box changes, because they
// depend on speech, which may or may not take the same time each "block" of 
// text.

// The text is split across frames by allowing a maximum of three newlines per
// paragraph. The text argument does not need any special formatting other than
// newlines built in as usual.

class Button;

enum class TextureSequenceName;

class TextCinematicPanel : public Panel
{
private:
	std::unique_ptr<Button> skipButton;
	TextureSequenceName sequenceName;
	std::string text;
	std::vector<double> secondsPerText;
	double secondsPerImage, currentImageSeconds, currentTextSeconds;
	int imageIndex, textIndex;
protected:
	virtual void handleEvents(bool &running) override;
	virtual void handleMouse(double dt) override;
	virtual void handleKeyboard(double dt) override;
public:
	TextCinematicPanel(GameState *gameState, TextureSequenceName name, 
		const std::string &text, const std::vector<double> &secondsPerText,
		double secondsPerImage, const std::function<void()> &endingAction);
	virtual ~TextCinematicPanel();

	static const double DEFAULT_MOVIE_SECONDS_PER_IMAGE;

	virtual void tick(double dt, bool &running) override;
	virtual void render(SDL_Surface *dst, const SDL_Rect *letterbox) override;
};

#endif
