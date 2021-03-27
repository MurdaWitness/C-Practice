using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class Menu : MonoBehaviour
{
    public Button playBtn;
    public Button exitBtn;
    void Start()
    {
        playBtn.onClick.AddListener(StartGame);
        exitBtn.onClick.AddListener(ExitGame);
    }

    void Update()
    {
        
    }

    public void StartGame()
    {
        SceneManager.LoadScene("Game");
    }
    public void ExitGame()
    {
        Application.Quit();
        Debug.Log("Осуществляю выход...");
    }
}
