using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BasicMover : MonoBehaviour {

    public float spinSpeed = 180.0f;
    public float motionMagnitude = 0.1f;
    public bool isSpin = true;
    public bool isMove = false;
	// Update is called once per frame
	void Update () {
        if (isSpin)
            gameObject.transform.Rotate(Vector3.up * spinSpeed * Time.deltaTime);
        if (isMove)
        gameObject.transform.Translate(Vector3.up * motionMagnitude * Mathf.Cos(Time.timeSinceLevelLoad));
	}
}
