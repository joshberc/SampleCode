using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(Rigidbody2D))]
public class PlayerController : MonoBehaviour
{
	#region ---- Variables ----
	//Public
	public float speed = 4.0f;
	public Camera MainCamera;
	public InventoryObject inventory;
	public Canvas ui;

	//Internal
	private float horizontal, vertical;
	private bool isPaused = false;
	private bool inventoryOpen = false;
	private Vector2 targetVector;
	private Rigidbody2D rig;
	private Animator anim;
	[SerializeField] private Interactable focus;
	#endregion

	#region ---- Main ----
	// Use this for initialization
	void Start()
	{
		rig = GetComponent<Rigidbody2D>();
		rig.freezeRotation = true;
		anim = GetComponent<Animator>();

		//Debug Messages
		Debug.Log("Paused:" + isPaused);
	}

	//Used for button presses and interactions
	void Update()
	{
		//Pause Game
		PauseGame();
		//Inventory Screen
		OpenInventory();
		//Interaction
		Interact();

		//TEMP Save/Load game.
		Save();
		Load();
	}

	//Used for Physics Movement
	void FixedUpdate()
	{

		//Movement
		// Gives a value between -1 and 1
		horizontal = Input.GetAxisRaw("Horizontal"); // -1 is left
		vertical = Input.GetAxisRaw("Vertical"); // -1 is down
		targetVector = new Vector2(horizontal, vertical);
		targetVector.Normalize();

		//Applies vector to rigidbody
		rig.velocity = targetVector * speed;


		//Apply Animations
		anim.SetFloat("Horizontal", Input.GetAxisRaw("Horizontal"));
		anim.SetFloat("Vertical", Input.GetAxisRaw("Vertical"));
		anim.SetFloat("Speed", rig.velocity.magnitude);


	}
	#endregion

	#region ---- Functions ----
	///<summary>
	///Toggles Time.timescale using the Input Managers Pause button.
	///</summary>
	void PauseGame()
	{
		//Pauses the game using the mapped pause key. Utilizes timescale to stop time movement.

		if (Input.GetButtonDown("Pause"))
		{
			//Toggles boolean
			isPaused = !isPaused;

			if (isPaused)
			{
				//Paused
				Time.timeScale = 0;
				Debug.Log("Game is Paused");

			}
			else
			{
				//Unpaused
				Time.timeScale = 1;
				Debug.Log("Game is Resumed");
			}
		}
	}

	///<summary>
	///Uses mouse right-click to interact with target object (which must have the Interactable script attached).
	///</summary>
	void Interact()
	{
		//When Player right-clicks on interactable object while within range.
		if (Input.GetMouseButtonDown(1))
		{
			Debug.Log("Player trying to select");
			//Creates 2D raycast and assigns the collider it hits
			RaycastHit2D hit = Physics2D.Raycast(Camera.main.ScreenToWorldPoint(Input.mousePosition), Vector2.zero);

			//If ray hits
			if(hit.collider != null) 
			{
				Debug.Log(hit);
				//Retrieve target "Interactable component" data
				Interactable interactable = hit.collider.GetComponent<Interactable>();

				if (interactable != null)
				{
					SetFocus(interactable);
				}
				else
				{
					RemoveFocus();
				}
			}
		}
	}

	///<summary>
	///Sets this objects focus to this interactable.
	///</summary>
	void SetFocus(Interactable newFocus)
	{
		if (newFocus != focus)
		{
			if (focus != null)
			{
				focus.Defocus();
			}
			focus = newFocus;
		}
		//Populates focused object with player data
		newFocus.Focus(this);

	}

	///<summary>
	///Removes Focus and sets it to null.
	///</summary>
	void RemoveFocus()
	{
		if (focus != null)
		{
			focus.Defocus();
		}
		focus = null;
	}

	///<summary>
	///Opens player Inventory UI in HUD.
	///</summary>
	void OpenInventory()
	{
		//Pauses the game using the mapped pause key. Utilizes timescale to stop time movement.

		if (Input.GetButtonDown("Inventory"))
		{
			//Toggles boolean
			inventoryOpen = !inventoryOpen;

            if (inventoryOpen)
            {
		
            }
            else
            {
		
            }
		}
	}

	void Save()
    {
        if (Input.GetKeyDown(KeyCode.Space))
        {
			inventory.Save();
			Debug.Log("Game Saved");
        }
    }

    void Load()
    {
		if (Input.GetKeyDown(KeyCode.L))
		{
			inventory.Load();
			Debug.Log("Game loaded");
		}
	}
    #endregion
}


