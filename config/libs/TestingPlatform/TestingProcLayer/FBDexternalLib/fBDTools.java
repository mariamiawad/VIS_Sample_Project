package libs.TestingPlatform.TestingProcLayer.FBDexternalLib;

import libs.TestingPlatform.TestingTechLayer.DecisonTableEntryValue;
/**
 * @author mteama
 * @version 1.0
 * @created 28-Aug-2017
 */

public class fBDTools {

	/**
	 * Join the modular arrays into one array
	 * @param any number of array
	 * @author mteama
	 */
    public static DecisonTableEntryValue[] joinArray(DecisonTableEntryValue[]... arrays) {
        int length = 0;
        for (DecisonTableEntryValue[] array : arrays) {
            length += array.length;
        }

        final DecisonTableEntryValue[] result = new DecisonTableEntryValue[length];

        int offset = 0;
        for (DecisonTableEntryValue[] array : arrays) {
            System.arraycopy(array, 0, result, offset, array.length);
            offset += array.length;
        }

        return result;
    }
}
