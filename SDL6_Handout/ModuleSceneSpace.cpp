#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleSceneSpace.h"
#include "ModuleSceneIntro.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleSceneSpace::ModuleSceneSpace()
{}

ModuleSceneSpace::~ModuleSceneSpace()
{}

// Load assets
bool ModuleSceneSpace::Start()
{
	LOG("Loading space scene");
	
	background = App->textures->Load("rtype/background.png");
	App->player->Enable();
	App->player->position.x = SCREEN_WIDTH/2;
	
	return true;
}

// UnLoad assets
bool ModuleSceneSpace::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);
	App->player->Disable();
	
	return true;
}

// Update: draw background
update_status ModuleSceneSpace::Update()
{
	// Move camera forward -----------------------------
	int scroll_speed = 1;

	App->player->position.x += 1;
	App->render->camera.x -= 3;
	
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN) {

		App->fade->FadeToBlack(App->scene_space, App->scene_intro, 1.5f);
	}

	// Draw everything --------------------------------------
	App->render->Blit(background, 0, 0, NULL);
	
	return UPDATE_CONTINUE;
}