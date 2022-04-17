# Change Log
## [0.0.8] - 04/17/2022
### Added
- Fleshed out all method and class level headers.
- Fleshed out Readme file.
### Fixed
- Updated mock json to properly include a valid item under one of the collections.
- Switched from [] map lookup to find.
## [0.0.7] - 03/29/2022
### Changed
- Finally got around to finishing this up. Functionally it's complete and the animation transitions work.
Need to document the classes and setup readme now. Have to switch gears to more algo study though.
## [0.0.6] - 03/20/2022
### Removed
- All references to the third person project setup.
- All UI testing code
## [0.0.5] - 03/17/2022
### Added
- Macro and Function library to try to unify how the show and hide methods on ViewControllers are invoked
in order to make it easier to call the animations.
### Changed
- Moved ViewControllerStack management to a Subsystem to be looked up and managed. I liked the idea
of it being an asset, but it's clear reading docs that unreal does not want you to do this.
### NOTE
- I would like to evaluate if animations are the optimal method for UI transitions with Unreal. In Unity
they are definitely not.
## [0.0.4] - 03/10/2022
### Added
- Setup basic foundation of ViewControllerStack, ViewController and the first CollectionView
## [0.0.3] - 03/09/2022
### Added
- Added riderlink plugin, took a bit of time to get this working.
- All models intended to be used with json loading of mock data.
## [0.0.2] - 03/06/2022
### Added
- Added mock json data, to allow access to it from the project via raw url.
## [0.0.1] - 03/04/2022
### Added 
- Setup basic project structure, primarily utilizing third-person project.
- Setup repro, and ignores.