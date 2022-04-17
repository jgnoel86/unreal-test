# Practicing Unreal UI development with services

## Project Structure
- _**MyContent** _Contains all of my project data, this is a common approach for me to keep my project data away from third party data._
  - **Data** _Contains the ViewControllerStack data table._
  - **GameModes** _Contains necessary files to get the UI to be the start of the project._
  - **Libraries** _Contains helper macros and libraries to ease managing ViewControllers._
  - **UMG** _All of the UI used in the application._

## Application Flow
- When the application launches, a call is made to retrieve the application data. 
  - The application data string is deserialized into valid unreal objects.
  - The starting collection object is grabbed and used to present the first ViewController.
- The first ViewController will be the starting collection from the service data. 
  - This starting collection contains a mix of collections and individual items.
  - All elements are presented on a clickable card of sorts, with a title and image.
  - Collections are presented with a stack icon in their upper right.
- When a user clicks on a collection, a new ViewController is pushed onto a ViewControllerStack, and the current stack top
is hidden.
  - The new ViewController presents in a similar fashion to the existing collection.
- When a user clicks on an item (any non-collection card), a new ViewController is pushed onto a ViewControllerStack, and 
the current stack top is hidden.
  - The new ViewController will contain a detail image, title, and description.
- At any level except the root level, the user can click the back button in the upper left to be taken out of their current
UI flow.
  - This will pop the top ViewController off the ViewController stack, and show the previous ViewController.

## Code Structure
### Data
###### AppDataStore
This game instance subsystem exists to have a central source to retrieve data for the application.
#### Model
All data models are prefixed with DM.
###### DMApp
The root Data Model is the DMApp object it contains a list
of DMCollection objects and DMItem objects. Here they are not organized, this is simply their fully
expanded data. 

DMApp also contains the starting collection id, this is the UUID for the collection that should act
essentially as the "Home" of an application. Though it could be interpreted in other ways.

###### DMURLAsset
Contains a UUID, as well as a url for where is asset is externally hosted. 

###### DMBase
Contains a UUID, name, and url asset representing this.

###### DMCollection _(DMBase)_
Contains a list of UUID(s) for the items this collection contains.

###### DMItem _(DMBase)_
Contains a description of this item.

### REST
Helper library to make REST calls.

### Widgets
###### CollectionView _(ViewController)_
Used to display a collection of cards representing content provided by the external service.

###### DetailView _(ViewController)_
Used to display a single unique item provided by the external service.

###### DMBaseItemCardView _(UUserWidget)_
Presents a single item in a clickable card form on a CollectionView.

#### ViewController
###### ViewController _(UUserWidget)_
The base user widget used to allow widgets to live in a stack. They provide a structured way of being shown and hidden, that 
allows the stack to be easily navigated.
###### ViewControllerStack _(UObject)_
A stack like its name that handles invoking the proper hide and show methods depending on whether a ViewController is being
pushed or popped.
###### ViewControllerStackManager _(UGameInstanceSubsystem)_
This exists because there is no great way to setup a stack as an assignable asset. Instead this manager exists, and a datatable
of stack names to ids exists to provide a way for other views to access a specific stack.