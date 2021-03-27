using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Music : MonoBehaviour
{
    public AudioSource source;
    public List<AudioClip> music;
    public int index;
    void Start()
    {
        source = GetComponent<AudioSource>();
        index = 0;
        ChangeOnPlay();
    }

    void Update()
    {
        
    }

    void ChangeOnPlay()
    {
        source.clip = music[index];
        var len = source.clip.length;
        source.Play();
        StartCoroutine(Timer(len));
    }

    IEnumerator Timer(float sec)
    {
        yield return new WaitForSeconds(sec);
        if (index + 1 == music.Count)
        index = 0;
        else index++;
        ChangeOnPlay();
    }


}
