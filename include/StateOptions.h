#ifndef _STATEOPTIONS_H_
#define _STATEOPTIONS_H_

#include "State.h"
#include "OptionsManager.h"

#include "go_image.h"
#include "go_font.h"


#include <vector>

using namespace std;

class Game;

/**
 * @class StateOptions
 *
 * @brief State for the main menu
 *
 * It manages the buttons of the main menu. The menu items are largely
 * dynamic. Also, there's an additional class that manages the animations of the
 * group of jewels that appear for decoration.
 *
 * @author José Tomás Tocino García <theom3ga@gmail.com>
 *
 */


class StateOptions : public State{
public:

    /// Creates a new StateOptions
    StateOptions(Game * p);

    /// It controls the animations and the transitions
    void update();

    /// Draws the different elements
    void draw();

    /**
     * @brief It gets called whenever the user presses a button.
     *
     * The user can press Up, Down and Return to select the menu entries, as
     * well as the mouse.
     *
     */
    void buttonDown(SDL_Keycode B);

    void mouseButtonDown(Uint8 button);

    void controllerButtonDown(Uint8 button);

    ~StateOptions();

private:

    /// Image for the background
    GoSDL::Image mImgBackground;

    /// Image for the logo
    GoSDL::Image mImgLogo;

    /// Image for the higlight of the menu entry
    GoSDL::Image mImgHighl;

    /// Font for the menu entries
    GoSDL::Font mFont;

    /// Current highlighted option
    unsigned int mMenuSelectedOption;

    /// List of menu options.
    vector<string> mMenuOptions;
    vector<GoSDL::Image> mMenuRenderedTexts;

    /// It gets executed when the user choses an option. It changes the state
    ///  to the proper one.
    void optionChosen();

    void moveUp();
    void moveDown();

    void updateButtonTexts();

    /// @{
    /// @name Coordinates of the menu elements
    int mMenuYStart, mMenuYEnd, mMenuYGap;
    /// @}

    OptionsManager mOptions;

};

#endif /* _STATEOPTIONS_H_ */
