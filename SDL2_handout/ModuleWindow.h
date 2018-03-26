#ifndef __ModuleWindow_H__
#define __ModuleWindow_H__

// TODO 1: Create the declaration of ModuleWindow class

class ModuleWindow : public Module {

	virtual bool Init() { return true; }
	virtual bool CleanUp() { return true; }
};


#endif // __ModuleWindow_H__