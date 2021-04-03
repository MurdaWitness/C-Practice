using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Spawner : MonoBehaviour
{
    [SerializeField] private Transform spawnPoint;
    [SerializeField] private GameObject ramp;
    [SerializeField] private GameObject ball;
    [SerializeField] private float rampChanceSpawn;
    [SerializeField] private float rateSpawn;
    void Start()
    {
        StartCoroutine(Timer(rateSpawn));
    }

    public void Spawn()
    {
        var random = Random.Range(0.0f, 1.0f);
        if (random >= rampChanceSpawn)
        {
            var pos = spawnPoint.position + new Vector3(0, 0.6f, 0);
            Instantiate(ball, pos, Quaternion.identity);
        }
        else Instantiate(ramp, spawnPoint.position, Quaternion.identity);
    }

    IEnumerator Timer(float rate)
    {
        while(true)
        {
            Spawn();
            yield return new WaitForSeconds(rate);
        }
    }
}
