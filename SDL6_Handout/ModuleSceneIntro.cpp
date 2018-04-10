#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleSceneSpace.h"
#include "ModuleSceneIntro.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneIntro::ModuleSceneIntro()
{}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading intro scene");

	IntroScreen = App->textures->Load("rtype/intro.png");
	App->render->camera.x = 0;
	App->player->Disable();
	
	_Mix_Music* mus = App->audio->LoadMus("rtype/intro.ogg");
	App->audio->PlayMus(mus);
	//App->scene_space->Enable();

	return true;
}

// UnLoad assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(IntroScreen);
	

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	
	if (App->input->keyboard[SDL_SCANCODE_SPACE]==1) {

		App->fade->FadeToBlack(App->scene_intro, App->scene_space, 1.5f);


	}

	// Draw everything --------------------------------------
	App->render->Blit(IntroScreen, 0, 0, NULL);

	return UPDATE_CONTINUE;
}