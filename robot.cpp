#include "modelerview.h"
#include "modelerapp.h"
#include "modelerdraw.h"
#include <FL/gl.h>

#include "modelerglobals.h"

enum RobotCtrls {
	X, Y, Z, 
	BODYHEIGHT, BODYWIDTH, NECKHEIGHT, HEADSCALE, 
	LEFTARM1VERTANGLE, LEFTARM2VERTANGLE, LEFTARM1HORIANGLE, LEFTARM2HORIANGLE, 
	RIGHTARM1VERTANGLE, RIGHTARM2VERTANGLE, RIGHTARM1HORIANGLE, RIGHTARM2HORIANGLE, 
	LEFTLEGVERTANGLE, LEFTLEGHORIANGLE, 
	RIGHTLEGVERTANGLE, RIGHTLEGHORIANGLE,
	TOTAL
};

class Robot : public ModelerView {
public:
	Robot(int x, int y, int w, int h, char* label) 
		: ModelerView(x, y, w, h, label) {}

	virtual void draw();
};

ModelerView* createRobot(int x, int y, int w, int h, char* label) {
	return new Robot(x, y, w, h, label);
}

void Robot::draw()
{
	ModelerView::draw();

	setAmbientColor(.1f, .1f, .1f);
	setDiffuseColor(COLOR_GREEN);

	glPushMatrix();
		glTranslated(VAL(X), VAL(Y), VAL(Z));

		glPushMatrix();
		glTranslated(0, 1, 0);
		glRotated(90, 1, 0, 0);
		drawCylinder(VAL(BODYHEIGHT), VAL(BODYWIDTH), VAL(BODYWIDTH));
			
			setAmbientColor(.1f, .1f, .1f);
			setDiffuseColor(COLOR_RED);
			glPushMatrix();
			glTranslated(VAL(BODYWIDTH), 0, 0.2 * VAL(BODYHEIGHT));
			drawSphere(0.075 * VAL(BODYHEIGHT));

			setAmbientColor(.1f, .1f, .1f);
			setDiffuseColor(COLOR_BLUE);
			glRotated(30, 0, 1, 0);
			drawCylinder(0.4 * VAL(BODYHEIGHT), 0.05 * VAL(BODYHEIGHT), 0.05 * VAL(BODYHEIGHT));

				glPushMatrix();
				glTranslated(0, 0, 0.4 * VAL(BODYHEIGHT));
				setAmbientColor(.1f, .1f, .1f);
				setDiffuseColor(COLOR_RED);
				drawSphere(0.075 * VAL(BODYHEIGHT));

				setAmbientColor(.1f, .1f, .1f);
				setDiffuseColor(COLOR_BLUE);
				glRotated(-30, 0, 1, 0);
				drawCylinder(0.4 * VAL(BODYHEIGHT), 0.05 * VAL(BODYHEIGHT), 0.05 * VAL(BODYHEIGHT));

					glPushMatrix();
					glTranslated(0, 0.07 * VAL(BODYHEIGHT), 0.4 * VAL(BODYHEIGHT));
	
					setAmbientColor(.1f, .1f, .1f);
					setDiffuseColor(COLOR_GREEN);
					glRotated(90, 1, 0, 0);
					drawCylinder(0.12 * VAL(BODYHEIGHT), 0.07 * VAL(BODYHEIGHT), 0.07 * VAL(BODYHEIGHT));

					glPopMatrix();

				glPopMatrix();

			glPopMatrix();

			setAmbientColor(.1f, .1f, .1f);
			setDiffuseColor(COLOR_RED);
			glPushMatrix();
			glTranslated(-VAL(BODYWIDTH), 0, 0.2 * VAL(BODYHEIGHT));
			drawSphere(0.075 * VAL(BODYHEIGHT));

			setAmbientColor(.1f, .1f, .1f);
			setDiffuseColor(COLOR_BLUE);
			glRotated(-30, 0, 1, 0);
			drawCylinder(0.4 * VAL(BODYHEIGHT), 0.05 * VAL(BODYHEIGHT), 0.05 * VAL(BODYHEIGHT));

				glPushMatrix();
				glTranslated(0, 0, 0.4 * VAL(BODYHEIGHT));
				setAmbientColor(.1f, .1f, .1f);
				setDiffuseColor(COLOR_RED);
				drawSphere(0.075 * VAL(BODYHEIGHT));

				setAmbientColor(.1f, .1f, .1f);
				setDiffuseColor(COLOR_BLUE);
				glRotated(30, 0, 1, 0);
				drawCylinder(0.4 * VAL(BODYHEIGHT), 0.05 * VAL(BODYHEIGHT), 0.05 * VAL(BODYHEIGHT));

					glPushMatrix();
					glTranslated(0, 0.07*VAL(BODYHEIGHT), 0.4 * VAL(BODYHEIGHT));

					setAmbientColor(.1f, .1f, .1f);
					setDiffuseColor(COLOR_GREEN);
					glRotated(90, 1, 0, 0);
					drawCylinder(0.12 * VAL(BODYHEIGHT), 0.07 * VAL(BODYHEIGHT), 0.07 * VAL(BODYHEIGHT));

					glPopMatrix();

				glPopMatrix();

			glPopMatrix();

			glPushMatrix();
			glRotated(180, 1, 0, 0);
			drawCylinder(VAL(NECKHEIGHT), 0.2 * VAL(BODYWIDTH), 0.2 * VAL(BODYWIDTH));

				glPushMatrix();
				glTranslated(-VAL(HEADSCALE) /2.0, -VAL(HEADSCALE) / 4.0, VAL(NECKHEIGHT));
				glScaled(VAL(HEADSCALE), VAL(HEADSCALE)/2.0, VAL(HEADSCALE)/2.0);
				drawBox(1, 1, 1);
				glPopMatrix();

			glPopMatrix();

			glPushMatrix();
			glTranslated(VAL(BODYWIDTH)/2.0, 0, VAL(BODYHEIGHT));

			setAmbientColor(.1f, .1f, .1f);
			setDiffuseColor(COLOR_RED);
			drawSphere(0.075 * VAL(BODYHEIGHT));

			setAmbientColor(.1f, .1f, .1f);
			setDiffuseColor(COLOR_BLUE);
			drawCylinder(0.4 * VAL(BODYHEIGHT), 0.05 * VAL(BODYHEIGHT), 0.05 * VAL(BODYHEIGHT));

				glPushMatrix();
				glTranslated(-0.1 * VAL(BODYHEIGHT), -0.1 * VAL(BODYHEIGHT), 0.4 * VAL(BODYHEIGHT));
				setAmbientColor(.1f, .1f, .1f);
				setDiffuseColor(COLOR_GREEN);
				drawBox(0.2 * VAL(BODYHEIGHT), 0.2 * VAL(BODYHEIGHT), 0.075 * VAL(BODYHEIGHT));
				glPopMatrix();
			
			glPopMatrix();

			glPushMatrix();
			glTranslated(-VAL(BODYWIDTH) / 2.0, 0, VAL(BODYHEIGHT));

			setAmbientColor(.1f, .1f, .1f);
			setDiffuseColor(COLOR_RED);
			drawSphere(0.075 * VAL(BODYHEIGHT));

			setAmbientColor(.1f, .1f, .1f);
			setDiffuseColor(COLOR_BLUE);
			drawCylinder(0.4 * VAL(BODYHEIGHT), 0.05 * VAL(BODYHEIGHT), 0.05 * VAL(BODYHEIGHT));

				glPushMatrix();
				glTranslated(-0.1 * VAL(BODYHEIGHT), -0.1 * VAL(BODYHEIGHT), 0.4 * VAL(BODYHEIGHT));
				setAmbientColor(.1f, .1f, .1f);
				setDiffuseColor(COLOR_GREEN);
				drawBox(0.2 * VAL(BODYHEIGHT), 0.2 * VAL(BODYHEIGHT), 0.075 * VAL(BODYHEIGHT));
				glPopMatrix();

			glPopMatrix();

		glPopMatrix();

	glPopMatrix();
}

int main() {
	ModelerControl controls[TOTAL];
	controls[X] = ModelerControl("X Position", -5, 5, 1, 0);
	controls[Y] = ModelerControl("Y Position", -5, 5, 1, 0);
	controls[Z] = ModelerControl("Z Position", -5, 5, 1, 0);
	controls[BODYHEIGHT] = ModelerControl("Body Height", 1.5f, 4.5f, 0.1f, 3.0f);
	controls[BODYWIDTH] = ModelerControl("Body Width", 1.0f, 2.0f, 0.1f, 1.3f);
	controls[NECKHEIGHT] = ModelerControl("Neck Height", 0.1f, 0.5f, 0.1f, 0.3f);
	controls[HEADSCALE] = ModelerControl("Head Scale", 1.5f, 3.0f, 0.1f, 2.0f);

	ModelerApplication::Instance()->Init(&createRobot, controls, TOTAL);
	return ModelerApplication::Instance()->Run();
}