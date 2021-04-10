using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Events;

public class MyDestr : MonoBehaviour
{
    public static UnityEvent borderPass;
    void Start()
    {
        borderPass = new UnityEvent(); 
    }

    private void OnTriggerEnter(Collider other)
    {
        Destroy(other.gameObject);
        borderPass?.Invoke();
    }
}
