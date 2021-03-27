using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Ball : MonoBehaviour
{
    public ColorControl cc;
    private void OnTriggerEnter(Collider other)
    {
        if (other.GetComponent<Player>() != null)
            if (true)
            {

            }
    }
}
