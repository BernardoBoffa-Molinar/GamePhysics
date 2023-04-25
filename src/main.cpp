#include "core/Application.h"
#include "scenes/TestScene.h"
<<<<<<< Updated upstream

int main(int argc, char** argv) {
    std::vector<Scene*> scenes = {
        new TestScene(),
=======
#include "scenes/FireworksScene.h"
#include "scenes/ImpulseScene.h"

int main(int argc, char** argv) {
    std::vector<Scene*> scenes = {
        new TestScene(), new FireworksScene(), new ImpulseScene()
>>>>>>> Stashed changes
    };
    Application app(scenes);
    // app.showDemoWindow(true);
    return app.run();
}
