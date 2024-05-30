using UnityEngine;
using System;

// Define the Event class
public class Event
{
    public DateTime Timestamp { get; set; }
    public string Description { get; set; }

    public Event(DateTime timestamp, string description)
    {
        Timestamp = timestamp;
        Description = description;
    }
}

// Define the TreeNode class
public class TreeNode
{
    public Event Event { get; set; }
    public TreeNode Left { get; set; }
    public TreeNode Right { get; set; }

    public TreeNode(Event e)
    {
        Event = e;
        Left = null;
        Right = null;
    }
}

// Define the BinarySearchTree class
public class BinarySearchTree
{
    private TreeNode root;

    public BinarySearchTree()
    {
        root = null;
    }

    // Insert a new event into the BST
    public void Insert(Event e)
    {
        root = InsertRec(root, e);
    }

    private TreeNode InsertRec(TreeNode root, Event e)
    {
        if (root == null)
        {
            root = new TreeNode(e);
        }
        else if (e.Timestamp < root.Event.Timestamp)
        {
            root.Left = InsertRec(root.Left, e);
        }
        else if (e.Timestamp > root.Event.Timestamp)
        {
            root.Right = InsertRec(root.Right, e);
        }
        return root;
    }

    // Inorder traversal to print events in sorted order
    public void InorderTraversal()
    {
        InorderTraversal(root);
    }

    private void InorderTraversal(TreeNode root)
    {
        if (root != null)
        {
            InorderTraversal(root.Left);    
            Debug.Log(root.Event.Timestamp.ToString("yyyy-MM-dd HH:mm:ss") + ": " + root.Event.Description);
            InorderTraversal(root.Right);
        }
    }

    // Search for events within a given time range
    public void SearchByTimeRange(DateTime startTime, DateTime endTime)
    {
        SearchByTimeRange(root, startTime, endTime);
    }

    private void SearchByTimeRange(TreeNode root, DateTime startTime, DateTime endTime)
    {
        if (root != null)
        {
            if (root.Event.Timestamp >= startTime && root.Event.Timestamp <= endTime)
            {
                Debug.Log(root.Event.Timestamp.ToString("yyyy-MM-dd HH:mm:ss") + ": " + root.Event.Description);
            }
            if (root.Event.Timestamp > startTime)
            {
                SearchByTimeRange(root.Left, startTime, endTime);
            }
            if (root.Event.Timestamp < endTime)
            {
                SearchByTimeRange(root.Right, startTime, endTime);
            }
        }
    }
}

// Main class to manage game state and test the BST
public class EventManager : MonoBehaviour
{
    // Define your game state variables here
    private int playerLevel = 1;
    private int playerExperience = 0;
    private int playerQuestsCompleted = 0;

    private BinarySearchTree eventBST;

    void Start()
    {
        // Create a BST to manage events
        eventBST = new BinarySearchTree();

        // Example: Insert some events
        InsertEvent(new DateTime(2024, 5, 20, 10, 0, 0), "Player smithed an item");
        InsertEvent(new DateTime(2024, 5, 21, 12, 0, 0), "Player leveled up");
        InsertEvent(new DateTime(2024, 5, 22, 14, 0, 0), "Player received a quest");
        InsertEvent(new DateTime(2024, 5, 23, 16, 0, 0), "Player completed a quest");
        InsertEvent(new DateTime(2024, 5, 24, 18, 0, 0), "Player unlocked a new skill");

        // Print events in sorted order
        Debug.Log("All events:");
        eventBST.InorderTraversal();
        Debug.Log("");

        // Search for events within a time range
        DateTime startTime = new DateTime(2024, 5, 21, 0, 0, 0);
        DateTime endTime = new DateTime(2024, 5, 23, 0, 0, 0);
        Debug.Log("Events between " + startTime.ToString("yyyy-MM-dd HH:mm:ss") + " and " + endTime.ToString("yyyy-MM-dd HH:mm:ss") + ":");
        eventBST.SearchByTimeRange(startTime, endTime);
    }

    // Method to insert an event into the BST and update game state
    public void InsertEvent(DateTime timestamp, string description)
    {
        Event newEvent = new Event(timestamp, description);
        eventBST.Insert(newEvent);

        // Example: Update game state based on the event description
        if (description.Contains("leveled up"))
        {
            playerLevel++;
        }
        else if (description.Contains("completed a quest"))
        {
            playerQuestsCompleted++;
        }
    }

    // Method to simulate player performance analysis
    public void AnalyzePlayerPerformance(DateTime startTime, DateTime endTime)
    {
        // Example: Search for events within the given time range
        eventBST.SearchByTimeRange(startTime, endTime);

        // Example: Calculate player performance metrics based on events within the time range
        // (This could include things like quests completed, experience gained, etc.)
    }
}
