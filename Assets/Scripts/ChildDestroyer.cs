using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Events;

public class ChildDestroyer : MonoBehaviour
{
    private void Start()
    {
        MyDestr.borderPass.AddListener(DestroyMyself);
    }
    public void DestroyMyself()
    {
        if (transform.childCount<1)
        {
            Destroy(this.gameObject);
        }
    }
}
