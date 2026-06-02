using UnityEngine;

public class HelloWorldTest : MonoBehaviour
{
    void Update()
    {
        if (Input.GetMouseButtonDown(0))
        {
            Debug.Log("HelloWorld");
        }
    }

    void OnGUI()
    {
        GUI.Label(new Rect(10, 10, 200, 30), "Hello World");
    }
}